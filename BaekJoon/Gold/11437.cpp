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

const int mxN = 50000;
int N, M;
vector<int> links[mxN];
int depth[mxN], par[mxN][16];

void dfs(int cur, int p){
    for(auto nxt: links[cur]){
        if(nxt == p) continue;
        depth[nxt] = depth[cur] + 1;
        par[nxt][0] = cur;
        dfs(nxt, cur);
    }
}

int LCA(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    for(int i = 15; i>=0; i--){
        if(depth[b] - depth[a] >= (1 << i)) b = par[b][i];
    }
    if(a == b) return a;
    for(int i = 15; i>=0; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    par[0][0] = -1;
    dfs(0, -1);
    rep(j, 1, 16) rep(i, 0, N){
        if(par[i][j-1] == -1) par[i][j] = -1;
        else par[i][j] = par[par[i][j-1]][j-1];
    }
    cin >> M;
    while(M--){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << LCA(a, b) + 1 << '\n';
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