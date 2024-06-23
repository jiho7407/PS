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

int N;
int C[100000];
vector<int> links[100000];
int deg[100000];
bool visited[100000];
map<int, int> mp;

int getSz(int cur, int par){
    deg[cur] = 1;
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        deg[cur] += getSz(nxt, cur);
    }
    return deg[cur];
}

int getCt(int cur, int par, int sz){
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        if(deg[nxt] > sz/2) return getCt(nxt, cur, sz);
    }
    return cur;
}

int calc(int cur, int par, int depth){
    int ret = 1e9;
    if(mp.count(C[cur])) ret = min(ret, mp[C[cur]] + depth);
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        ret = min(ret, calc(nxt, cur, depth+1));
    }
    return ret;
}

void update(int cur, int par, int depth){
    if(mp.count(C[cur])) mp[C[cur]] = min(mp[C[cur]], depth);
    else mp[C[cur]] = depth;
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        update(nxt, cur, depth+1);
    }
}

int DnC(int cur){
    int sz = getSz(cur, -1);
    int ct = getCt(cur, -1, sz);

    visited[ct] = true;
    mp.clear();
    mp[C[ct]] = 0;
    int ret = 1e9;
    for(auto nxt : links[ct]){
        if(visited[nxt]) continue;
        ret = min(ret, calc(nxt, ct, 1));
        update(nxt, ct, 1);
    }

    for(auto nxt : links[ct]){
        if(visited[nxt]) continue;
        ret = min(ret, DnC(nxt));
    }

    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> C[i];
    rep(i, 0, N-1){
        int u, v; cin >> u >> v;
        u--, v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    fill(visited, visited+N, false);
    cout << DnC(0);
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