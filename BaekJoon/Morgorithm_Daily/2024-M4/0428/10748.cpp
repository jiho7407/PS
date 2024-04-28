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

const int mod = 1e9+7;
int R, C, K;
int board[100][100];
int DP[100][100];

int calc(int r, int c){
    if(r < 0 || c < 0) return 0;
    if(DP[r][c] != -1) return DP[r][c];
    int ret = 0;
    rep(i, 0, r) rep(j, 0, c) {
        if(board[i][j] == board[r][c]) continue;
        ret += calc(i, j);
        ret %= mod;
    }
    return DP[r][c] = ret;
}

void solve(){
    cin >> R >> C >> K;
    rep(i, 0, R) rep(j, 0, C) cin >> board[i][j];
    rep(i, 0, R) fill(DP[i], DP[i]+C, -1);
    DP[0][0] = 1;
    cout << calc(R-1, C-1) << '\n';
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