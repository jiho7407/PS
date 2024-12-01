#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

// Segment Tree
struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return a*b;
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(sz*2, 1);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 1;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

int N, Q;


void solve(){
    while(cin >> N >> Q){
        ST.init(N);
        rep(i, 0, N){
            int x;
            cin >> x;
            if(x > 0) x = 1;
            if(x < 0) x = -1;
            ST.set(i, x);
        }
        ST.build();

        while(Q--){
            char op; int a, b;
            cin >> op >> a >> b;
            if(op == 'C'){
                if(b > 0) ST.update(a-1, 1);
                if(b < 0) ST.update(a-1, -1);
                if(b == 0) ST.update(a-1, 0);
            }
            else{
                int ret = ST.query(a-1, b-1);
                if(ret > 0) cout << '+';
                if(ret < 0) cout << '-';
                if(ret == 0) cout << '0';
            }
        }
        cout << '\n';
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}