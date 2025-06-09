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
int cost[16][16];
int DP[16][1<<16];

void solve(){
    cin >> N;
    rep(i, 0, N) rep(j, 0, N) cin >> cost[i][j];
    rep(i, 0, N) rep(j, 0, 1<<N) DP[i][j] = 1e9;
    DP[0][1] = 0;
    rep(mask, 1, 1<<N){
        rep(i, 0, N){
            if(!(mask & (1<<i))) continue;
            rep(j, 0, N){
                if(mask & (1<<j)) continue;
                DP[j][mask | (1<<j)] = min(DP[j][mask | (1<<j)], DP[i][mask] + cost[i][j]);
            }
        }
    }
    int ans = 1e9;
    rep(i, 1, N) ans = min(ans, DP[i][(1<<N)-1] + cost[i][0]);
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