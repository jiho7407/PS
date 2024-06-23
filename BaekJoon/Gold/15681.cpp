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

int N, R, Q;
vector<int> links[100000];
int deg[100000];

int maketree(int cur, int par){
    deg[cur] = 1;
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        deg[cur] += maketree(nxt, cur);
    }
    return deg[cur];
}

void solve(){
    cin >> N >> R >> Q; R--;
    rep(i, 0, N-1){
        int u, v; cin >> u >> v; u--; v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    maketree(R, -1);
    while(Q--){
        int u; cin >> u; u--;
        cout << deg[u] << '\n';
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