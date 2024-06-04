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

int N, M, A, B;
int board[100][100];
int DP[100][100];
int dx[2] = {1, 0}, dy[4] = {0, 1};

void solve(){
    cin >> N >> M >> A >> B;
    fill_n(&DP[0][0], 100*100, 0);
    fill_n(&board[0][0], 100*100, 0);
    rep(i, 0, A){
        int x, y; cin >> x >> y; x--; y--;
        board[x][y] = 1; // 아이템
        for(int a = x+1, b = y-1; a<N && b>=0; a++, b--) board[a][b] = 2;
        for(int a = x-1, b = y+1; a>=0 && b<M; a--, b++) board[a][b] = 2;
    } 
    rep(i, 0, B){
        int x, y; cin >> x >> y; x--; y--;
        board[x][y] = 2; // 장애물
    }
    DP[0][0] = 1;
    rep(i, 0, N) rep(j, 0, M){
        if(DP[i][j] == 0) continue;
        rep(k, 0, 2){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(board[nx][ny] == 2) continue;
            DP[nx][ny] += DP[i][j];
        }
    }
    // rep(i, 0, N){
    //     rep(j, 0, M) cout << board[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // rep(i, 0, N){
    //     rep(j, 0, M) cout << DP[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << DP[N-1][M-1] << '\n';
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