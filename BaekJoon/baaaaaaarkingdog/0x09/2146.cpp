#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, test;
    cin >> N;
    queue<pair<int, int>> Q;
    for(int i = 0; i<N; i++){
        fill(visited[i], visited[i]+N, false);
        for(int j = 0; j<N; j++){
            cin >> test;
            board[i][j] = test;
        }
    }
    int island = 1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(visited[i][j] || board[i][j] == 0) continue;
            Q.push({i,j});
            island += 1;
            board[i][j] = island;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int d = 0; d<4; d++){
                    int px = cur.first + dx[d];
                    int py = cur.second + dy[d];
                    if(px<0 || px>=N || py<0 || py>=N) continue;
                    if(visited[px][py] || board[px][py] == 0) continue;
                    board[px][py] = island;
                    visited[px][py] = true;
                    Q.push({px, py});
                }
            }
        }
    }
    
    int ans = 200;
    queue<tuple<int, int, int>> Q2;
    for(int curisland = 2; curisland <= island; curisland++){
        for(int i = 0; i<N; i++){
            fill(visited[i], visited[i]+N, false);
            for(int j = 0; j<N; j++){
                if(board[i][j] == curisland){
                    Q2.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        while(!Q2.empty()){
            auto cur = Q2.front(); Q2.pop();
            int curx, cury, level;
            tie(curx, cury, level) = cur;
            for(int d = 0; d<4; d++){
                int px = curx + dx[d];
                int py = cury + dy[d];
                if(px<0 || px>=N || py<0 || py>=N) continue;
                if(visited[px][py]) continue;
                if(board[px][py] == 0){
                    visited[px][py] = true;
                    Q2.push({px, py, level+1});
                }
                else{
                    ans = min(ans, level);
                }
            }
        }
    }

    // for(int i = 0; i<N; i++){
    //     for(int j = 0; j<N; j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans;
}