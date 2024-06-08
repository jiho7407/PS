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

int N, M;
vector<pii> links[25];
bool used[25];

int btr(int node){
    int ret = 0;
    for(auto [nxt, idx]: links[node]){
        if(used[idx]) continue;
        used[idx] = true;
        ret = max(ret, btr(nxt)+1);
        used[idx] = false;
    }
    return ret;
}

void solve(){
    while(1){
        cin >> N >> M;
        if(N+M==0) break;
        rep(i, 0, M){
            int a, b; cin >> a >> b;
            links[a].push_back({b, i});
            links[b].push_back({a, i});
        }
        fill(used, used+N, false);
        int ans = 0;
        rep(i, 0, N) ans = max(ans, btr(i));
        cout << ans << '\n';
        rep(i, 0, N) links[i].clear();
    }
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