/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
#define all(x) (x).begin(), (x).end()
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

int N;
pii p[200000];
vector<int> x[100001], y[100001];
int color[200000];
int group = 0;
int cnt[100000][2];

void dfs(int cur){
    if(cur < N) cnt[group][color[cur]-1]++;
    auto [a, b] = p[cur];
    for(int nxt: x[a]){
        if(nxt == cur) continue;
        if(color[nxt]) continue;
        color[nxt] = 3 - color[cur];
        dfs(nxt);
    }
    for(int nxt: y[b]){
        if(nxt == cur) continue;
        if(color[nxt]) continue;
        color[nxt] = 3 - color[cur];
        dfs(nxt);
    }
}

void solve(){
    cin >> N;
    rep(i, 0, 2*N){
        int a, b; cin >> a >> b;
        p[i] = {a, b};
        x[a].push_back(i);
        y[b].push_back(i);
    }
    rep(i, 1, N+1){
        if(x[i].size() != 2 || y[i].size() != 2){
            cout << -1;
            return;
        }
    }
    rep(i, 0, 2*N) if(!color[i]){
        color[i] = 1;
        dfs(i);
        group++;
    }
    int ans = 0;
    // rep(i, 0, group+1){
    //     cout << cnt[i][0] << ' ' << cnt[i][1] << '\n';
    // }
    rep(i, 0, group+1) ans += min(cnt[i][0], cnt[i][1]);
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