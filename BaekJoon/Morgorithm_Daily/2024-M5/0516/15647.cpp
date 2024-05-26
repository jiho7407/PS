#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll mxN = 3e5;
ll N;
vector<pii> links[mxN];
ll child[mxN], dist[mxN];
ll ans[mxN];

void dfs(ll cur, ll par){
    ll tmpdist = 0;
    for(auto [nxt, cost]: links[cur]){
        if(nxt == par) continue;
        dfs(nxt, cur);
        child[cur] += child[nxt];
        tmpdist += dist[nxt] + cost * child[nxt];
    }
    dist[cur] = tmpdist;
    return;
}

void dfs2(ll cur, ll par){
    for(auto [nxt, cost]: links[cur]){
        if(nxt == par) continue;
        ans[nxt] = ans[cur] + (N - 2 * child[nxt]) * cost;
        dfs2(nxt, cur);
    }
    return;
}


void solve(){
    cin >> N;
    rep(i, 0, N-1){
        ll a, b, d; cin >> a >> b >> d; a--; b--;
        links[a].push_back({b, d});
        links[b].push_back({a, d});
    }
    fill(child, child+N, 1);
    fill(dist, dist+N, 0);
    fill(ans, ans+N, 0);
    dfs(0, -1);
    ans[0] = dist[0];
    dfs2(0, -1);
    rep(i, 0, N){
        cout << ans[i] << '\n';
    }
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}