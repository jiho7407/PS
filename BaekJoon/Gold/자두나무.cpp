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

int DP[1010][35][2];
void solve(){
    int T, W; cin >> T >> W;
    rep(i, 0, T+1) rep(j, 0, W+1) rep(k, 0, 2) DP[i][j][k] = -1e9;
    DP[0][0][0] = 0;
    rep(i, 1, T+1){
        int a; cin >> a;
        rep(j, 0, W+1){
            DP[i][j][0] = max(DP[i][j][0], DP[i-1][j][0]);
            if(j > 0) DP[i][j][0] = max(DP[i][j][0], DP[i-1][j-1][1]);
            DP[i][j][0] += (a == 1);

            DP[i][j][1] = max(DP[i][j][1], DP[i-1][j][1]);
            if(j > 0) DP[i][j][1] = max(DP[i][j][1], DP[i-1][j-1][0]);
            DP[i][j][1] += (a == 2);
        }
    }
    int ans = 0;
    rep(i, 0, W+1) ans = max(ans, max(DP[T][i][0], DP[T][i][1]));
    cout << ans;
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