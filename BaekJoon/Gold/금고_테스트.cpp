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

int DP[505][505];

int calc(int n, int k){
    if(n <= 0) return 0;
    if(k <= 0) return 1e9;
    if(DP[n][k] != -1) return DP[n][k];
    DP[n][k] = 1e9;
    rep(i, 1, n+1){
        int ret = max(calc(i-1, k-1), calc(n - i, k)) + 1;
        DP[n][k] = min(DP[n][k], ret);
    }
    return DP[n][k];
}


void solve(){
    int N, K; cin >> N >> K;
    rep(i, 0, N+1) rep(j, 0, K+1) DP[i][j] = -1;
    cout << calc(N, K);
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