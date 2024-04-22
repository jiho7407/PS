#include <bits/stdc++.h>
using namespace std;

int cost[510][510];
string board[510];
deque<pair<int, int>> dq;
int dx[4] = {-1, 0, 0, -1};
int dy[4] = {-1, -1, 0, 0};
int sx[4] = {-1, 1, 1, -1};
int sy[4] = {-1, -1, 1, 1};

int main(void){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i <=N; i++){
        fill(cost[i], cost[i]+M+1, -1);
    }
    string cmd;
    for(int i = 0; i<N; i++){
        cin >> cmd;
        board[i] = cmd;
    }

    dq.push_back({0, 0});
    cost[0][0] = 0;
    int x, y, d;
    while(!dq.empty()){
        auto [x, y] = dq.front(); dq.pop_front();
        for(int i = 0; i<4; i++){
            int px, py, tx, ty;
            px = x + dx[i];
            py = y + dy[i];
            tx = x + sx[i];
            ty = y + sy[i];

            if(px < 0 or px > N or py < 0 or py > M) continue;
            
            if(i%2){
                if(board[px][py] == '/' and (cost[tx][ty] == -1 or cost[tx][ty] > cost[x][y])){
                    dq.push_front({tx, ty});
                    cost[tx][ty] = cost[x][y];
                }
                if(board[px][py] == '\\' and (cost[tx][ty] == -1 or cost[tx][ty] > cost[x][y] + 1)){
                    dq.push_back({tx, ty});
                    cost[tx][ty] = cost[x][y] + 1;
                }
            }
            else{
                if(board[px][py] == '\\' and (cost[tx][ty] == -1 or cost[tx][ty] > cost[x][y])){
                    dq.push_front({tx, ty});
                    cost[tx][ty] = cost[x][y];
                }
                if(board[px][py] == '/' and (cost[tx][ty] == -1 or cost[tx][ty] > cost[x][y] + 1)){
                    dq.push_back({tx, ty});
                    cost[tx][ty] = cost[x][y] + 1;
                }
            }
        }
        // for(int i = 0; i<=N; i++){
        //     for(int j = 0; j<=M; j++){
        //         cout << cost[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    int ans;
    ans = cost[N][M];
    if(ans == -1){
        cout << "NO SOLUTION";
    }
    else{
        cout << ans;
    }

}