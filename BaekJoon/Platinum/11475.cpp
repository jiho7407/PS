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
        return min(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.assign(sz*2, 1e9);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = min(tree[idx], x);
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 1e9;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

int N, T;
int P[50050], D[50050];

bool check(int mid){
    ST.init(N);
    ST.set(0, 0);
    ST.build();
    rep(i, 1, N){
        int val = ST.query(max(0, i-mid), i-1);
        ST.update(i, val + D[i]);
    }
    return ST.query(N-1, N-1) + N-1 <= T;
}

void solve(){
    cin >> N >> T;
    rep(i, 1, N) cin >> P[i];
    rep(i, 1, N-1) cin >> D[i];

    int ok = N-1, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    int ans = 1e9;
    rep(i, ok, N) ans = min(ans, P[i]);
    cout << ans << '\n';
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