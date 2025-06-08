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

struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return max(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

void solve(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    
    ST.init(N);
    for(int i = 0, j = 0; i<N; i++){
        while(j < N && A[i]*2 > A[j]) j++;
        ST.set(i, j-i);
    }
    ST.build();
    
    int Q; cin >> Q;
    while(Q--){
        int L, R; cin >> L >> R; L--; R--;
        int ok = 0, ng = (R-L+1)/2+1;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            if(L + mid + ST.query(L, L+mid-1) <= R+1) ok = mid;
            else ng = mid;
        }
        cout << ok << '\n';
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