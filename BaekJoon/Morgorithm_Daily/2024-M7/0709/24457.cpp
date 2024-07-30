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
pll drink[5000];
ll DP[5001][5000];

bool cmp(pii a, pii b){
    return a.second > b.second;
}

ll calc(ll i, ll j){
    if(i > j+1) return -1e18;
    if(DP[i][j] != -1) return DP[i][j];
    auto [E, C] = drink[j];
    return DP[i][j] = max(calc(i, j-1), calc(i-1, j-1) + E - C*(i-1));
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> drink[i].first;
    rep(i, 0, N) cin >> drink[i].second;
    sort(drink, drink+N, cmp);

    fill_n(&DP[0][0], 5001*5000, -1);
    fill(DP[0], DP[0]+N, 0);
    ll ans = 0;
    rep(i, 0, N+1) rep(j, 0, N) ans = max(ans, calc(i, j));

    // rep(i, 0, N+1){
    //     rep(j, 0, N){
    //         cout << DP[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
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