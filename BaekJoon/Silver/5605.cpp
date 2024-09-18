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
vector<pii> links[101]; // nxt, idx;
int DP[101];
bool visited[101];

bool appear[101];

pii dfs(int cur, int dist){
    appear[cur] = false;
    pii ret = {dist, cur};
    for(auto [nxt, idx]: links[cur]){
        if(visited[nxt]) continue;
        visited[nxt] = true;
        ret = max(ret, dfs(nxt, dist+1));
        visited[nxt] = false;
    }
    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, b; cin >> a >> b;
        links[a].push_back({b, i});
        links[b].push_back({a, i});
        appear[a] = appear[b] = true;
    }

    pii ans = {0, 0};
    rep(i, 1, 101){
        pii end1;
        if(!appear[i]) continue;
        visited[i] = true;
        end1 = dfs(i, 1);
        visited[i] = false;
        visited[end1.second] = true;
        pii end2 = dfs(end1.second, 1);
        visited[end1.second] = false;
        // cout << i << ' ' << end1.first << ' ' << end2.first << '\n';
        ans = max(ans, end2);
    }
    cout << ans.first;
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