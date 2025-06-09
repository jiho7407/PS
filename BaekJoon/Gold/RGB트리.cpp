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

int N;
vector<int> links[500000];
int Beauty[500000][3], DP[500000][3], ans[500000];

int calc(int cur, int color, int par){
    if(DP[cur][color] != -1) return DP[cur][color];
    int &ret = DP[cur][color] = 0;
    ret += Beauty[cur][color];
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        int mx = -1e9;
        rep(nc, 0, 3) if(color != nc) mx = max(mx, calc(nxt, nc, cur));
        ret += mx;
    }
    return ret;
}

void dfs(int cur, int par, int color){
    ans[cur] = color;

    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        int mx = -1e9, mxcolor = -1;
        rep(nc, 0, 3) if(color != nc){
            if(mx < calc(nxt, nc, cur)){
                mx = calc(nxt, nc, cur);
                mxcolor = nc;
            }
        }
        dfs(nxt, cur, mxcolor);
    }
}

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int u, v; cin >> u >> v;
        u--, v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    rep(i, 0, N) rep(j, 0, 3) cin >> Beauty[i][j], DP[i][j] = -1;

    int mxidx = -1, mx = -1;
    rep(i, 0, 3){
        if(mx < calc(0, i, -1)) mx = calc(0, i, -1), mxidx = i;
    }
    dfs(0, -1, mxidx);
    vector<char> v = {'R', 'G', 'B'};
    
    cout << mx << '\n';
    rep(i, 0, N) cout << v[ans[i]];
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