#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(void){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    queue<pair<int,int>> Q;
    int ans = 0, cnt;
    for(int k = 0; k<=100; k++){
        cnt = 0;
        for(int v = 0; v<N; v++){
            fill(visited[v], visited[v]+N, false);
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(visited[i][j] || k >= board[i][j]) continue;
                cnt++;
                Q.push({i, j});
                visited[i][j] = true;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int d = 0; d<4; d++){
                        int px = cur.first + dx[d];
                        int py = cur.second + dy[d];
                        if(px<0 || px>=N || py<0 || py>=N) continue;
                        if(visited[px][py] || k >= board[px][py]) continue;
                        visited[px][py] = true;
                        Q.push({px, py});
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}