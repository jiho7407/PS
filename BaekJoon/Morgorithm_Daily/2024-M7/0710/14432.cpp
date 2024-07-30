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

ll N, M, ans;
vector<ll> links[100000];
ll W[100000], DP[100000];

void dfs(ll cur, ll par){
    ll mx = 0;
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        dfs(nxt, cur);
        mx = max(mx, W[nxt]);
    }
    if(par == -1) mx = max(mx, W[cur]);
    ans += mx;
    W[cur] -= mx;
    for(auto nxt: links[cur]) W[nxt] -= mx;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> W[i];
    rep(i, 0, M){
        ll a, b; cin >> a >> b;
        a--, b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    dfs(0, -1);
    cout << ans;
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