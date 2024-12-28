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

int N, M, L;
vector<pii> links[100000];
bool visited[100000];
vector<int> diag, rad;

pii dfs1(int cur, int par){
    visited[cur] = true;
    pii ret = {0, cur};
    for(auto [nxt, L]: links[cur]){
        if(nxt == par) continue;
        auto [dist, node] = dfs1(nxt, cur);
        ret = max(ret, {dist+L, node});
    }
    return ret;
}

vector<int> path;

bool findpath(int cur, int par, int goal){
    path.push_back(cur);
    if(cur == goal){
        return true;
    }
    for(auto [nxt, L]: links[cur]){
        if(nxt == par) continue;
        if(findpath(nxt, cur, goal)){
            return true;
        }
    }
    path.pop_back();
    return false;
}

pii findCenter(int dist){
    int curd = 0;
    int n = path.size();
    rep(i, 0, n-1){
        for(auto [nxt, L]: links[path[i]]){
            if(nxt != path[i+1]) continue;
            curd += L;
            if(curd*2 >= dist) return {path[i], path[i+1]};
        }
    }
    cout << "error" << '\n';
    for(auto i: path) cout << i << ' '; cout << '\n';
    cout << curd << ' ' << dist << '\n';
    assert(false);
}

int dfs4(int cur, int par){
    int ret = 0;
    for(auto [nxt, L]: links[cur]){
        if(nxt == par) continue;
        ret = max(ret, dfs4(nxt, cur)+L);
    }
    return ret;
}

void solve(){
    cin >> N >> M >> L;

    rep(i, 0, M){
        int a, b, c; cin >> a >> b >> c;
        links[a].push_back({b, c});
        links[b].push_back({a, c});
    }

    rep(i, 0, N){
        if(visited[i]) continue;
        auto [dist1, node1] = dfs1(i, -1);
        auto [dist2, node2] = dfs1(node1, -1);
        diag.push_back(dist2);
        if(node1 == node2){
            rad.push_back(dist1);
            continue;
        }
        path.clear();
        path.push_back(node1);
        findpath(node1, -1, node2);
        pii res = findCenter(dist2);
        rad.push_back(min(dfs4(res.first, -1), dfs4(res.second, -1)));
    }

    sort(diag.begin(), diag.end(), greater<int>());
    sort(rad.begin(), rad.end(), greater<int>());

    int ans = 0;
    ans = max(ans, diag[0]);
    if(rad.size() >= 2) ans = max(ans, rad[0] + rad[1] + L);
    if(rad.size() >= 3) ans = max(ans, rad[1] + rad[2] + 2*L);
    cout << ans << '\n';
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