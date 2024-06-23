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
    ll cnt[32];
    Node(){
        fill(cnt, cnt+32, 0);
    }
};

struct LazySegmentTree{
    ll sz = 1;
    vector<Node> tree;
    vector<ll> lazy;

    void init(ll N){
        while(sz < N) sz *= 2;
        tree.resize(2*sz);
        lazy.resize(2*sz);
    }

    void push(ll node, ll start, ll end){
        if(!lazy[node]) return;
        bool changed[32];
        fill(changed, changed+32, false);
        rep(i, 0, 32){
            if(changed[i]) continue;
            swap(tree[node].cnt[i], tree[node].cnt[i^lazy[node]]);
            changed[i] = changed[i^lazy[node]] = true;
        }
        if(start != end){
            lazy[2*node] ^= lazy[node];
            lazy[2*node+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }

    Node pull(Node a, Node b){
        Node ret;
        rep(i, 0, 32) ret.cnt[i] = a.cnt[i] + b.cnt[i];
        return ret;
    }

    void set(ll idx, ll val){
        tree[sz+idx].cnt[val] = 1;
    }

    void build(){
        for(ll i = sz-1; i > 0; i--){
            tree[i] = pull(tree[2*i], tree[2*i+1]);
        }
    }

    void update(ll s, ll e, ll val){
        update(1, 0, sz-1, s, e, val);
    }

    void update(ll node, ll s, ll e, ll qs, ll qe, ll val){
        push(node, s, e);
        if(qs > e || qe < s) return;
        if(qs <= s && e <= qe){
            lazy[node] ^= val;
            push(node, s, e);
            return;
        }
        ll m = (s+e)/2;
        update(2*node, s, m, qs, qe, val);
        update(2*node+1, m+1, e, qs, qe, val);
        tree[node] = pull(tree[2*node], tree[2*node+1]);
    }

    Node query(){
        return query(1, 0, sz-1, 0, sz-1);
    }

    Node query(ll s, ll e){
        return query(1, 0, sz-1, s, e);
    }

    Node query(ll node, ll s, ll e, ll qs, ll qe){
        push(node, s, e);
        if(qs > e || qe < s) return Node();
        if(qs <= s && e <= qe) return tree[node];
        ll m = (s+e)/2;
        Node lq = query(2*node, s, m, qs, qe);
        Node rq = query(2*node+1, m+1, e, qs, qe);
        return pull(lq, rq);
    }
}ST;

const ll mxN = 100000;
vector<pii> links[mxN];
ll start[mxN], finish[mxN], depth[mxN], idx = 0;
map<pii, ll> weight;

void dfs(ll c, ll p, ll d, ll val){
    start[c] = idx++;
    depth[c] = d;
    ST.set(start[c], val);
    for(auto [n, w]: links[c]){
        if(n == p) continue;
        dfs(n, c, d+1, val^w);
    }
    finish[c] = idx-1;
}


void solve(){
    ll N, M; cin >> N >> M;
    ST.init(N);
    rep(i, 0, N-1){
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        links[u].push_back({v, w});
        links[v].push_back({u, w});
        weight[{u, v}] = weight[{v, u}] = w;
    }
    dfs(0, -1, 0, 0);
    ST.build();

    while(M--){
        ll op; cin >> op;
        if(op == 1){
            ll u, v, w; cin >> u >> v >> w;
            u--; v--;
            if(depth[u] > depth[v]) swap(u, v);
            ST.update(start[v], finish[v], w^weight[{u, v}]);
            weight[{u, v}] = weight[{v, u}] = w;
        }
        else{
            ll c; cin >> c;
            Node tmp = ST.query();
            ll ans = 0;
            rep(i, 0, 32){
                ans += 1LL*tmp.cnt[i]*(tmp.cnt[c^i]);
            }
            cout << ans/2 << '\n';
        }
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