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

int DP[101][100001];

void solve(){
    int N, K; cin >> N >> K;
    rep(i, 0, N+1) rep(j, 0, K+1) DP[i][j] = -1e9;
    DP[0][0] = 0;
    int ans = 0;
    rep(i, 0, N){
        int w, v; cin >> w >> v;
        rep(j, 0, K+1){
            if(DP[i][j] >= 0){
                DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
                if(j + w <= K) DP[i+1][j+w] = max(DP[i+1][j+w], DP[i][j] + v);
            }
        }
    }
    rep(i, 0, K+1) ans = max(ans, DP[N][i]);
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