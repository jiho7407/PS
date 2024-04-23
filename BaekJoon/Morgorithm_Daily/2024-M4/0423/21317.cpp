#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, K;
int E[21][2], DP[21][2];

void solve(){
    cin >> N;
    rep(i, 1, N) cin >> E[i][0] >> E[i][1];
    cin >> K;
    rep(i, 0, N+1) DP[i][0] = DP[i][1] = 1e9;
    DP[1][0] = 0;
    rep(j, 0, 2){
        rep(i, 1, N){
            if(DP[i][j] == 1e9) continue;
            if(i + 1 <= N) DP[i+1][j] = min(DP[i+1][j], DP[i][j] + E[i][0]);
            if(i + 2 <= N) DP[i+2][j] = min(DP[i+2][j], DP[i][j] + E[i][1]);
            if(j==0 && i + 3 <= N) DP[i+3][j+1] = min(DP[i+3][j+1], DP[i][j] + K);
        }
    }
    cout << min(DP[N][0], DP[N][1]) << '\n';
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