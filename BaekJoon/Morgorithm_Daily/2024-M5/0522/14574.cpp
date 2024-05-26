#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N;
pll cook[1000];
ll score[1000][1000];
ll root[1000];
vector<int> links[1000];

ll findroot(ll x){
    if(root[x] == x) return x;
    return root[x] = findroot(root[x]);
}

void merge(ll x, ll y){
    x = findroot(x);
    y = findroot(y);
    if(x == y) return;
    if(x < y) root[y] = x;
    else root[x] = y;
    return;
}

void getscore(ll i, ll j){
    ll sc = (cook[i].second + cook[j].second) / abs(cook[i].first - cook[j].first);
    score[i][j] = sc;
    score[j][i] = sc;
    return;
}

void maketree(){
    priority_queue<tll> pq;
    rep(i, 0, N) rep(j, i+1, N) pq.push({score[i][j], i, j});
    rep(i, 0, N) root[i] = i;
    ll ans = 0;
    while(!pq.empty()){
        auto [sc, i, j] = pq.top(); pq.pop();
        if(findroot(i) == findroot(j)) continue;
        merge(i, j);
        ans += sc;
        links[i].push_back(j);
        links[j].push_back(i);
    }
    cout << ans << '\n';
    return;
}

void dfs(ll cur, ll par){
    for(auto nxt : links[cur]){
        if(nxt == par) continue;
        dfs(nxt, cur);
    }
    if(par == -1) return;
    cout << par+1 << ' ' << cur+1 << '\n';
    return;
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> cook[i].first >> cook[i].second;
    fill_n(score[0], 1000*1000, 0);
    rep(i, 0, N) rep(j, i+1, N) getscore(i, j);
    maketree();
    dfs(0, -1);
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