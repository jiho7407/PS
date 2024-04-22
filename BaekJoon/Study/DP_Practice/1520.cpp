#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int board[501][501], DP[502][501];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int solve(int i, int j){
    if(DP[i][j] != -1) return DP[i][j];
    int result = 0;
    for(int d = 0; d<4; d++){
        int px, py;
        px = i + dx[d];
        py = j + dy[d];
        if(px<0 || px>=N || py<0 || py>=M) continue;
        if(board[px][py] <= board[i][j]) continue;
        result += solve(px, py);
    }
    DP[i][j] = result;
    return result;
}

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        fill(DP[i], DP[i]+M, -1);
    }

    DP[0][0] = 1;
    
    cout << solve(N-1, M-1);
    return 0;
}