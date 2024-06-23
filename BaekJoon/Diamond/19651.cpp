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
    ll sum = 0, pf = 0, sf = 0, mf = 0, sz = 0;
    Node(ll v){
        if(v == 0) pf = sf = mf = 1;
        sum = v;
        sz = 1;
    }
};

struct SegmentTree{
    ll sz = 1;
    vector<Node> tree;
    void init(ll N){
        while(sz < N) sz *= 2;
        tree.resize(2*sz, Node(1));
    }

    Node pull(Node a, Node b){
        Node ret(1);
        ret.sum = a.sum + b.sum;
        if(a.pf == a.sz) ret.pf = a.sz + b.pf;
        else ret.pf = a.pf;
        if(b.sf == b.sz) ret.sf = b.sz + a.sf;
        else ret.sf = b.sf;
        ret.mf = max({a.mf, b.mf, a.sf + b.pf});
        ret.sz = a.sz + b.sz;
        return ret;
    }

    void set(ll idx, ll v){
        tree[idx+sz] = Node(v);
    }
    void build(){
        for(ll i = sz-1; i>0; i--){
            tree[i] = pull(tree[i<<1], tree[i<<1|1]);
        }
    }

    void update(ll idx, ll v){
        idx += sz;
        ll val = tree[idx].sum + v;
        tree[idx] = Node(val);
        while(idx >>= 1){
            tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
        }
    }

    Node query(ll l, ll r){
        if(l > r) return Node(1);
        return query(1, 0, sz-1, l, r);
    }

    Node query(ll node, ll s, ll e, ll qs, ll qe){
        if(qs > e || qe < s) return Node(1);
        if(qs <= s && e <= qe) return tree[node];
        ll m = (s+e)>>1;
        Node lq = query(node<<1, s, m, qs, qe);
        Node rq = query(node<<1|1, m+1, e, qs, qe);
        return pull(lq, rq);
    }
}ST;

ll N, M;
ll A[100000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    ST.init(max(10LL, N-2));
    rep(i, 0, N-2){
        ST.set(i, A[i] + A[i+2] - 2*A[i+1]);
    }
    ST.build();

    cin >> M;
    while(M--){
        ll op; cin >> op;
        if(op == 1){
            ll l, r, a, d; cin >> l >> r >> a >> d;
            if(l-3 >= 0) ST.update(l-3, a);
            if(l-2 >= 0) ST.update(l-2, -a+d);
            if(r-2 < N-2) ST.update(r-2, -a-(r-l+1)*d);
            if(r-1 < N-2) ST.update(r-1, a + (r-l)*d);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << ST.query(l-1, r-3).mf + 2 << '\n';
        }
        // rep(i, 0, ST.sz) cout << ST.tree[i+ST.sz].sum << ' ';
        // cout << '\n';
    }
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