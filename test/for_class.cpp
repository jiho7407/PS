#include <bits/stdc++.h>
using namespace std;


int dist[4][4];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int cx, int cy){
    for(int d = 0; d<4; d++){
        int nx = cx + dx[d], ny = cy + dy[d];
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if(dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[cx][cy] + 1;
        dfs(nx, ny);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill_n(&dist[0][0], 4*4, -1);
    dist[0][0] = 1;
    dfs(0, 0);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}


