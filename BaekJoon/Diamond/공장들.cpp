/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, l, r) for(int i = r-1; i >= l; i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 500050;
const int mxp = 19;

int N, Q;
vector<pii> links[mxN];
int in[mxN], out[mxN]; // ETT
int depth[mxN], parent[mxp][mxN]; // LCA
ll dist[mxN];
int idx = 0;

vector<int> factory;
int color[mxN];
vector<pll> links2[mxN];
ll dist2[mxN];

void ETT(int cur, int par){
    in[cur] = idx++;
    parent[0][cur] = par;
    for(auto [nxt, w]: links[cur]){
        if(nxt == par) continue;
        depth[nxt] = depth[cur] + 1;
        dist[nxt] = dist[cur] + w;
        ETT(nxt, cur);
    }
}

int getLCA(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    rrep(i, 0, mxp) if((diff >> i) & 1) v = parent[i][v];
    if(u == v) return u;
    rrep(i, 0, mxp) if(parent[i][u] != parent[i][v]){
        u = parent[i][u];
        v = parent[i][v];
    }
    return parent[0][u];
}

bool cmp(int a, int b){
    return in[a] < in[b];
}

void solve(){
    // Input Tree
    cin >> N >> Q;
    rep(i, 0, N-1){
        int u, v, w; cin >> u >> v >> w;
        links[u].push_back({v, w});
        links[v].push_back({u, w});
    }
    
    // preprocess
    ETT(0, -1);
    rep(i, 1, mxp) rep(j, 0, N) parent[i][j] = parent[i-1][parent[i-1][j]];
    rep(i, 0, N) dist2[i] = 1e18;
    
    
    // Input Query
    while(Q--){
        int S, T; cin >> S >> T;
        rep(i, 0, S){
            int x; cin >> x;
            factory.push_back(x);
            color[x] = 1;
        }
        rep(i, 0, T){
            int x; cin >> x;
            factory.push_back(x);
            color[x] = 2;
        }

        // Tree Compression
        sort(all(factory), cmp);
        int sz = factory.size();
        rep(i, 0, sz-1) factory.push_back(getLCA(factory[i], factory[i+1]));
        sort(all(factory), cmp);
        factory.erase(unique(all(factory)), factory.end());

        // Build Compressed Tree
        sz = factory.size();
        // cout << "Factory Size: " << sz << endl;
        rep(i, 0, sz-1){
            int u = getLCA(factory[i], factory[i+1]), v = factory[i+1];
            if(u == v) continue;
            ll w = dist[v] - dist[u];
            assert(w >= 0);
            links2[u].push_back({v, w});
            links2[v].push_back({u, w});
        }

        // Dijkstra
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        for(auto x: factory) if(color[x] == 1){
            dist2[x] = 0;
            pq.push({0, x});
        }
        while(!pq.empty()){
            auto [d, cur] = pq.top(); pq.pop();
            if(d > dist2[cur]) continue;
            if(color[cur] == 2){
                cout << d << '\n';
                break;
            }
            for(auto [nxt, w]: links2[cur]){
                if(dist2[nxt] > d + w){
                    dist2[nxt] = d + w;
                    pq.push({dist2[nxt], nxt});
                }
            }
        }

        // Reset
        for(auto x: factory) {
            color[x] = 0;
            links2[x].clear();
            dist2[x] = 1e18;
        }
        factory.clear();
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