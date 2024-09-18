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

struct Tree{
    int mxN, idx;
    vector<vector<int>> links, child, par;
    vector<int> sz, depth, top, in, out, rev;

    void init(int N){
        mxN = N;
        idx = 0;
        links.resize(N);
        child.resize(N);
        sz.resize(N);
        depth.resize(N);
        top.resize(N);
        in.resize(N);
        out.resize(N);
        par.resize(20, vector<int>(N));
        rev.resize(N);
    }

    void add_edge(int u, int v){
        links[u].push_back(v);
        links[v].push_back(u);
    }

    void make_tree(int c, int p){
        for(auto& nxt : links[c]){
            if(nxt == p) continue;
            child[c].push_back(nxt);
            make_tree(nxt, c);
        }
    }

    void dfs1(int c, int p){
        sz[c] = 1;
        for(auto& nxt : child[c]){
            depth[nxt] = depth[c] + 1;
            par[0][nxt] = c;
            dfs1(nxt, c);
            sz[c] += sz[nxt];
            if(sz[nxt] > sz[child[c][0]]) swap(nxt, child[c][0]);
        }
    }

    void dfs2(int c, int p){
        rev[idx] = c;
        in[c] = idx++;
        for(auto& nxt : child[c]){
            if(nxt == child[c][0]) top[nxt] = top[c];
            else top[nxt] = nxt;
            dfs2(nxt, c);
        }
        out[c] = idx;
    }

    void lca_init(){
        rep(i, 1, 20) rep(j, 0, mxN){
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }

    int lca(int u, int v){
        if(depth[u] > depth[v]) swap(u, v);
        rep(i, 0, 20) if((depth[v] - depth[u]) & (1<<i)) v = par[i][v];
        if(u == v) return u;
        for(int i = 19; i >= 0; i--){
            if(par[i][u] != par[i][v]){
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }

    int get_dist(int u, int v){
        return depth[u] + depth[v] - 2*depth[lca(u, v)];
    }

    void build(){
        make_tree(0, -1);
        dfs1(0, -1);
        dfs2(0, -1);
        lca_init();
    }
}Tree;

void solve(){
    int N; cin >> N;
    Tree.init(N);
    rep(i, 0, N-1){
        int u, v; cin >> u >> v;
        Tree.add_edge(u-1, v-1);
    }
    Tree.build();
    int M; cin >> M;
    while(M--){
        int u, v; cin >> u >> v;
        cout << Tree.lca(u-1, v-1)+1 << '\n';
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