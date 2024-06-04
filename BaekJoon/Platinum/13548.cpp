#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int sq;
struct Query{
    int idx, l, r;

    Query(int idx, int l, int r): idx(idx), l(l), r(r){}

    bool operator<(const Query &q) const{
        if(l/sq == q.l/sq) return r < q.r;
        return l/sq < q.l/sq;
    }
};

struct SegmentTree{
    vector<int> tree;
    int sz;

    void pull(int node){
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] += x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) pull(i);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) pull(idx);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++]);
            if((right&1)==0) ret = max(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

int N, M;
int A[100000], ans[100000];
vector<Query> Q;

void solve(){
    cin >> N; sq = sqrt(N); ST.init(100001);
    rep(i, 0, N) cin >> A[i];
    cin >> M;
    rep(i, 0, M){
        int l, r; cin >> l >> r; l--; r--;
        Q.push_back(Query(i, l, r));
    }
    sort(Q.begin(), Q.end());

    int lp = Q[0].l, rp = Q[0].r;
    rep(i, lp, rp+1) ST.update(A[i], 1);
    ST.build();
    ans[Q[0].idx] = ST.query(0, 100001);

    rep(i, 1, M){
        auto [idx, l, r] = Q[i];
        while(lp < l) ST.update(A[lp++], -1);
        while(lp > l) ST.update(A[--lp], 1);
        while(rp < r) ST.update(A[++rp], 1);
        while(rp > r) ST.update(A[rp--], -1);
        ans[idx] = ST.query(0, 100001);
    }
    rep(i, 0, M) cout << ans[i] << '\n';
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