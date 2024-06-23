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

int N, M;
vector<int> links[100000];
int par[18][100000];
int depth[100000];

int deg[100000];
bool visited[100000];
int CTpar[100000];

void maketree(int c, int p = -1){
    for(auto n: links[c]){
        if(n == p) continue;
        depth[n] = depth[c] + 1;
        par[0][n] = c;
        maketree(n, c);
    }
}

void makeLCA(){
    rep(j, 1, 18) rep(i, 0, N){
        par[j][i] = par[j-1][par[j-1][i]];
    }
}

int LCA(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    int diff = depth[b] - depth[a];
    rep(i, 0, 18) if(diff & (1<<i)) b = par[i][b];
    if(a == b) return a;
    for(int i = 17; i >= 0; i--){
        if(par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}

int getDist(int a, int b){
    return depth[a] + depth[b] - 2*depth[LCA(a, b)];
}

int getSz(int c, int p){
    deg[c] = 1;
    for(auto n: links[c]){
        if(n == p || visited[n]) continue;
        deg[c] += getSz(n, c);
    }
    return deg[c];
}

int getCt(int c, int p, int sz){
    for(auto n: links[c]){
        if(n == p || visited[n]) continue;
        if(deg[n] > sz/2) return getCt(n, c, sz);
    }
    return c;
}

void makeCT(int c, int p = -1){
    int sz = getSz(c, p);
    int ct = getCt(c, p, sz);
    visited[ct] = true;

    if(p != -1) CTpar[ct] = p;
    else CTpar[ct] = ct;

    for(auto n: links[ct]){
        if(visited[n]) continue;
        makeCT(n, ct);
    }
}

bool white[100000];
multiset<int> ms[100000];

void update(int v){
    white[v] ^= 1;
    int u = v;
    while(1){
        int dist = getDist(u, v);
        if(white[v]) ms[u].insert(dist);
        else ms[u].erase(ms[u].find(dist));
        if(u == CTpar[u]) break;
        u = CTpar[u];
    }
}

int query(int v){
    int ret = 1e9;
    int u = v;
    while(1){
        if(ms[u].size()){
            int dist = getDist(u, v);
            ret = min(ret, dist + *ms[u].begin());
        }
        if(u == CTpar[u]) break;
        u = CTpar[u];
    }
    if(ret == 1e9) return -1;
    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int u, v; cin >> u >> v; u--; v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    fill_n(&par[0][0], 100000*18, -1);
    fill(depth, depth+N, 0);
    fill(visited, visited+N, false);
    maketree(0);
    makeLCA();
    makeCT(0);

    fill(white, white+N, false);
    cin >> M;
    while(M--){
        int op; cin >> op;
        if(op == 1){
            int i; cin >> i; i--;
            update(i);
        }
        else{
            int v; cin >> v; v--;
            cout << query(v) << '\n';
        }
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