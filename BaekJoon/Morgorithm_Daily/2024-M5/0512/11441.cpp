#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return a + b;
    }
    void init(int N, vector<int>& lst){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
        for(int i = 0; i < N; i++){
            tree[sz+i] = lst[i];
        }
        for(int i = sz-1; i > 0; i--){
            tree[i] = pull(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
        }
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
};

void solve(){
    int N; cin >> N;
    vector<int> lst(N);
    rep(i, 0, N) cin >> lst[i];
    SegmentTree ST;
    ST.init(N, lst);
    int M; cin >> M;    
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        cout << ST.query(a-1, b-1) << '\n';
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}