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

int N, K;
int deg[200000];
vector<pii> links[200000];
bool visited[200000];
map<int, int> mp;

int getSz(int cur, int par){
    deg[cur] = 1;
    for(auto [nxt, w]: links[cur]){
        if(nxt == par || visited[nxt]) continue;
        deg[cur] += getSz(nxt, cur);
    }
    return deg[cur];
}

int getCent(int cur, int par, int sz){
    for(auto [nxt, w]: links[cur]){
        if(nxt == par || visited[nxt]) continue;
        if(deg[nxt] > sz/2) return getCent(nxt, cur, sz);
    }
    return cur;
}

int getDist(int cur, int par, int dist, int depth){
    int ret = 1e9;

    if(dist > K) return ret;
    if(mp.count(K-dist)) ret = mp[K-dist] + depth;

    for(auto [nxt, w]: links[cur]){
        if(nxt == par || visited[nxt]) continue;
        ret = min(ret, getDist(nxt, cur, dist+w, depth+1));
    }
    return ret;
}

void update(int cur, int par, int dist, int depth){
    if(dist > K) return;
    if(mp.count(dist)) mp[dist] = min(mp[dist], depth);
    else mp[dist] = depth;

    for(auto [nxt, w]: links[cur]){
        if(nxt == par || visited[nxt]) continue;
        update(nxt, cur, dist+w, depth+1);
    }
}

int DnC(int cur){
    int sz = getSz(cur, -1);
    int cent = getCent(cur, -1, sz);
    visited[cent] = true;
    mp.clear();
    mp[0] = 0;

    int ret = 1e9;

    for(auto [nxt, w]: links[cent]){
        if(visited[nxt]) continue;
        ret = min(ret, getDist(nxt, cent, w, 1));
        update(nxt, cent, w, 1);
    }

    for(auto [nxt, w]: links[cent]){
        if(visited[nxt]) continue;
        ret = min(ret, DnC(nxt));
    }

    return ret;
}


void solve(){
    cin >> N >> K;
    rep(i, 0, N-1){
        int a, b, w; cin >> a >> b >> w;
        links[a].push_back({b, w});
        links[b].push_back({a, w});
    }
    fill(visited, visited+N, false);
    int ans = DnC(0);
    if(ans == 1e9) cout << -1;
    else cout << ans;
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