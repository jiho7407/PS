#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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

const int mxN = 500500;
int N, Q;
vector<pll> links[mxN];
ll par[mxN][20], dist[mxN][20];
int depth[mxN];

void maketree(int c, int p = -1){
    for(auto [n, w]: links[c]){
        if(n == p) continue;
        depth[n] = depth[c] + 1;
        par[n][0] = c;
        dist[n][0] = w;
        maketree(n, c);
    }
}

void makeLCA(){
    rep(j, 1, 20) rep(i, 0, N){
        par[i][j] = par[par[i][j-1]][j-1];
        dist[i][j] = dist[i][j-1] + dist[par[i][j-1]][j-1];
    }
}

ll getDist(int a, int b){
    ll ret = 0;
    if(depth[a] > depth[b]) swap(a, b);
    int diff = depth[b] - depth[a];
    rep(i, 0, 20) if(diff & (1 << i)){
        ret += dist[b][i];
        b = par[b][i];
    }
    if(a == b) return ret;
    for(int i = 19; i >= 0; i--){
        if(par[a][i] != par[b][i]){
            ret += dist[a][i] + dist[b][i];
            a = par[a][i];
            b = par[b][i];
        }
    }
    return ret + dist[a][0] + dist[b][0];
}

int deg[mxN];
bool visited[mxN];
int CT[mxN];
ll CTdist[mxN];

int getSz(int c, int p = -1){
    deg[c] = 1;
    for(auto [n, w]: links[c]){
        if(n == p || visited[n]) continue;
        deg[c] += getSz(n, c);
    }
    return deg[c];
}

int getCt(int c, int p, int sz){
    for(auto [n, w]: links[c]){
        if(n == p || visited[n]) continue;
        if(deg[n] > sz/2) return getCt(n, c, sz);
    }
    return c;
}

void decompose(int c, int p = -1){
    int sz = getSz(c);
    int ct = getCt(c, -1, sz);
    visited[ct] = true;

    if(p == -1) CT[ct] = ct;
    else CT[ct] = p;

    for(auto [n, w]: links[ct]){
        if(visited[n]) continue;
        decompose(n, ct);
    }
}

void update(int v){
    int u = v;
    while(1){
        CTdist[u] = min(CTdist[u], getDist(u, v));
        if(u == CT[u]) break;
        u = CT[u];
    }
}

ll query(int v){
    ll ret = 1e18;
    int u = v;
    while(1){
        ret = min(ret, CTdist[u] + getDist(u, v));
        if(u == CT[u]) break;
        u = CT[u];
    }
    return ret;
}

void solve(){
    cin >> N >> Q;
    rep(i, 0, N-1){
        int u, v, w; cin >> u >> v >> w;
        links[u].push_back({v, w});
        links[v].push_back({u, w});
    }
    fill_n(&par[0][0], mxN*20, -1);
    fill_n(&dist[0][0], mxN*20, 0);
    maketree(0);
    makeLCA();
    decompose(0);

    while(Q--){
        fill_n(CTdist, mxN, 1e18);
        int S, T; cin >> S >> T;
        while(S--){
            ll x; cin >> x;
            update(x);
        }
        ll ret = 1e18;
        while(T--){
            ll x; cin >> x;
            ret = min(ret, query(x));
        }
        cout << ret << '\n';
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