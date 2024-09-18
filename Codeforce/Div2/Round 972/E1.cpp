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

int L, N, M;
int board[300][300];
int A[300];
int DP[300][300][300];

int dfs(int idx, int x, int y){
    if(idx == L) return 0;
    if(x >= N || y >= M) return 0;
    int &ret = DP[idx][x][y];
    if(ret != -1) return ret;

    for(int i = N-1; i >= x; i--) for(int j = M-1; j >= y; j--){
        if(board[i][j] != A[idx]) continue;
        if(dfs(idx+1, i+1, j+1) == 0) return ret = 1;
    }
    return ret = 0;
}

void solve(){
    cin >> L >> N >> M;
    rep(i, 0, L) cin >> A[i];
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    rep(i, 0, L) rep(j, 0, N) rep(k, 0, M) DP[i][j][k] = -1;
    if(dfs(0, 0, 0) == 1) cout << "T\n";
    else cout << "N\n";
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}