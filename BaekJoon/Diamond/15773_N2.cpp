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
vector<pll> balloons;
ll DP[5001][5001];

bool cmp(pll a, pll b){
    return a.first + a.second < b.first + b.second;
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll L, D; cin >> L >> D;
        balloons.push_back({L, D});
    }
    sort(balloons.begin(), balloons.end(), cmp);

    fill_n(&DP[0][0], 5001*5001, 1e18);
    DP[0][0] = 0;
    rep(i, 0, N){
        auto [L, D] = balloons[i];
        rep(j, 0, N){
            DP[i+1][j] = min(DP[i+1][j], DP[i][j]);
            if(DP[i][j] <= L) DP[i+1][j+1] = min(DP[i+1][j+1], DP[i][j] + D);
        }
    }
    // rep(i, 0, N+1){
    //     rep(j, 0, N+1) cout << DP[i][j] << ' ';
    //     cout << '\n';
    // }
    int ans = 0;
    rep(i, 0, N+1) if(DP[N][i] < 1e18) ans = i;
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