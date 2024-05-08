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

int N, M, H;
ll board[1000][1000];
ll DP[1000][1000];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    cin >> H;
    rep(i, 0, N) fill(DP[i], DP[i]+M, 1e18);
    DP[0][0] = board[0][0];
    rep(i, 0, N) rep(j, 0, M){
        if(i+1 < N) DP[i+1][j] = min(DP[i+1][j], DP[i][j] + board[i+1][j]);
        if(j+1 < M) DP[i][j+1] = min(DP[i][j+1], DP[i][j] + board[i][j+1]);
    }
    if(DP[N-1][M-1] <= H) cout << "YES\n" << DP[N-1][M-1] << '\n';
    else cout << "NO\n";
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