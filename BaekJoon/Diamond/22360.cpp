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

ll N;
string S;
ll deg[200000];
vector<ll> links[200000];
bool visited[200000];
map<tuple<ll, ll, ll>, ll> mp; // (U, C, P) -> cnt

ll getSz(ll cur, ll par){
    deg[cur] = 1;
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        deg[cur] += getSz(nxt, cur);
    }
    return deg[cur];
}

ll getCt(ll cur, ll par, ll sz){
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        if(deg[nxt] > sz/2) return getCt(nxt, cur, sz);
    }
    return cur;
}

void dfs(ll cur, ll par, tuple<ll, ll, ll> state){
    auto [U, C, P] = state;
    if(S[cur] == 'U') U++;
    else if(S[cur] == 'C') C++;
    else P++;
    ll mn = min({U, C/2, P});
    U -= mn, C -= 2*mn, P -= mn;
    mp[{U, C, P}]++;
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        dfs(nxt, cur, {U, C, P});
    }
}

ll dfs2(ll cur, ll par, tuple<ll, ll, ll> state){
    auto [U, C, P] = state;
    if(S[cur] == 'U') U++;
    else if(S[cur] == 'C') C++;
    else P++;
    ll mx = max({U, (C+1)/2, P});
    ll ret = 0;
    ret += mp[{mx-U, 2*mx-C, mx-P}];
    // if(mp[{mx-U, 2*mx-C, mx-P}] > 0){
    //     cout << "found " << cur << ' ' << mx-U << ' ' << 2*mx-C << ' ' << mx-P << ' ' << mp[{mx-U, 2*mx-C, mx-P}] << '\n';
    // }
    for(auto nxt : links[cur]){
        if(nxt == par || visited[nxt]) continue;
        ret += dfs2(nxt, cur, {U, C, P});
    }
    return ret;
}

ll DnC(ll cur){
    ll sz = getSz(cur, -1);
    ll ct = getCt(cur, -1, sz);
    visited[ct] = true;
    mp.clear();
    mp[{0, 0, 0}] = 1;

    ll ret = 0;
    for(auto nxt : links[ct]){
        if(visited[nxt]) continue;
        ret += dfs2(nxt, ct, {S[ct] == 'U', S[ct] == 'C', S[ct] == 'P'});
        dfs(nxt, ct, {0, 0, 0});
    }
    // cout << cur << ' ' << ct << '\n';
    // for(auto [key, val] : mp){
    //     cout << get<0>(key) << ' ' << get<1>(key) << ' ' << get<2>(key) << ' ' << val << '\n';
    // }
    for(auto nxt : links[ct]){
        if(visited[nxt]) continue;
        ret += DnC(nxt);
    }
    return ret;
}


void solve(){
    cin >> N >> S;
    rep(i, 0, N-1){
        ll a, b; cin >> a >> b; a--, b--;
        links[a].push_back(b);
        links[b].push_back(a);
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