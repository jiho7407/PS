/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, Q;
ll par[19][500001];
vector<ll> links[500001];
ll depth[500001];
ll in[500001], out[500001]; // ETT
vector<ll> links2[500001];
ll cnt[500001];

void ETT(int cur, int par){
    static int idx = 0;
    in[cur] = idx++;
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        depth[nxt] = depth[cur] + 1;
        ETT(nxt, cur);
    }
    out[cur] = idx;
}

int getLCA(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    rrep(i, 19, 0) if((diff >> i) & 1) v = par[i][v];
    if(u == v) return u;
    rrep(i, 19, 0) if(par[i][u] != par[i][v]){
        u = par[i][u];
        v = par[i][v];
    }
    return par[0][u];
}

ll dfs(int cur, int par){
    bool flag = cnt[cur] ? true : false;
    ll ret = 0;
    for(auto nxt: links2[cur]){
        if(nxt == par) continue;
        ret += dfs(nxt, cur);
        cnt[cur] += cnt[nxt];
    }
    for(auto nxt: links2[cur]){
        if(nxt == par) continue;
        ret += (ll) depth[cur] * cnt[nxt] * (cnt[cur] - cnt[nxt]);
    }
    if(flag) ret += (ll) depth[cur] * (cnt[cur] - 1);
    return ret;
}

void solve(){
    cin >> N >> Q;
    rep(i, 2, N+1){
        cin >> par[0][i];
        links[par[0][i]].push_back(i);
        links[i].push_back(par[0][i]);
    }
    rep(i, 1, 19) rep(j, 1, N+1) par[i][j] = par[i-1][par[i-1][j]];
    ETT(1, 0);
    while(Q--){
        int K; cin >> K;
        vector<int> nodes(K);
        rep(i, 0, K) cin >> nodes[i];
        rep(i, 0, K) cnt[nodes[i]]++;
        sort(all(nodes), [](int a, int b) { return in[a] < in[b]; });
        int sz = nodes.size();
        rep(i, 0, sz-1) nodes.push_back(getLCA(nodes[i], nodes[i+1]));
        sort(all(nodes), [](int a, int b) { return in[a] < in[b]; });
        nodes.erase(unique(all(nodes)), nodes.end());
        sz = nodes.size();
        rep(i, 0, sz-1){
            int u = getLCA(nodes[i], nodes[i+1]), v = nodes[i+1];
            if(u == v) continue;
            links2[u].push_back(v);
            links2[v].push_back(u);
        }
        cout << dfs(nodes[0], -1)/2 << '\n';
        for(auto x: nodes){
            cnt[x] = 0;
            links2[x].clear();
        }
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