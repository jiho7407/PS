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

const int INF = 1e9;
int N, M, T;
int dist[300][300];

void solve(){
    cin >> N >> M >> T;
    fill_n(&dist[0][0], 300*300, INF);
    while(M--){
        int u, v, h; cin >> u >> v >> h; u--; v--;
        dist[u][v] = h;
    }
    rep(k, 0, N) rep(i, 0, N) rep(j, 0, N){
        dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
    }
    while(T--){
        int s, e; cin >> s >> e; s--; e--;
        cout << (dist[s][e] == INF ? -1 : dist[s][e]) << '\n';
    }
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