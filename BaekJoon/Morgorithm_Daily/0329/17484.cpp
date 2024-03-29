#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int board[7][6];
int dy[3] = {-1, 0, 1};

int btr(int x, int y, int dir, int cost){
    if(x==N) return cost;
    int temp = 123456789;
    for(int d = 0; d<3; d++){
        if(d==dir) continue;
        int py = y + dy[d];
        if(py < 0 or py>=M) continue;
        temp = min(temp, btr(x+1, py, d, cost+board[x+1][py]));
    }
    return temp;
}

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) cin >> board[i][j];
    }
    fill(board[N], board[N]+M, 0);
    int ans = 123456789;
    for(int i = 0; i<M; i++) ans = min(ans, btr(0, i, -1, board[0][i]));
    cout << ans;
    return 0;
}