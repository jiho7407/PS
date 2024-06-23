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

struct Node{
    ll m, n;
    Node(ll m, ll n) : m(m), n(n) {}
    Node() : m(0), n(0) {}
};

struct SegmentTree{
    ll sz = 1;
    vector<Node> tree;

    void init(ll N){
        while(sz<N) sz <<= 1;
        tree.resize(sz*2);
    }

    Node pull(Node a, Node b){
        return Node(a.m+b.m, a.n+b.n);
    }

    void update(ll H, ll A, ll B){
        update(0, {-B, H*B});
        update(H, {A+B, -H*A - H*B});
    }

    void update(ll idx, pll val){
        idx += sz;
        tree[idx].m += val.first;
        tree[idx].n += val.second;
        while(idx>>=1){
            tree[idx].m += val.first;
            tree[idx].n += val.second;
        }
    }

    ll query(ll H){
        Node tmp = query(1, 0, sz-1, 0, H);
        return tmp.m*H + tmp.n;
    }

    Node query(ll node, ll s, ll e, ll qs, ll qe){
        if(qs<=s && e<=qe) return tree[node];
        if(e<qs || qe<s) return {0, 0};
        ll m = (s+e)/2;
        Node lq = query(node*2, s, m, qs, qe);
        Node rq = query(node*2+1, m+1, e, qs, qe);
        return pull(lq, rq);
    }
}ST;

ll N, K;
vector<ll> H, A, B;

ll calc(){
    ll lo = 0, hi = 100000;
    while(hi-lo > 2){
        ll m1 = (lo*2+hi)/3;
        ll m2 = (lo+hi*2)/3;
        ll f1 = ST.query(m1), f2 = ST.query(m2);
        if(f1 < f2) hi = m2;
        else lo = m1;
    }
    ll ret = 1e18;
    rep(i, lo, hi+1) ret = min(ret, ST.query(i));
    return ret;
}

void solve(){
    cin >> N >> K;
    H.resize(N), A.resize(N), B.resize(N);
    rep(i, 0, N) cin >> H[i];
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    ST.init(100001);
    rep(i, 0, K) ST.update(H[i], A[i], B[i]);

    ll ans = 1e18;
    rep(i, K, N){
        ans = min(ans, calc());
        ST.update(H[i], A[i], B[i]);
        ST.update(H[i-K], -A[i-K], -B[i-K]);
    }
    ans = min(ans, calc());
    cout << ans << '\n';
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