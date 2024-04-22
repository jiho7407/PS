#include <bits/stdc++.h>
using namespace std;

string board[31][31];
int dist[31][31][31];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int main(void){
    while(true){
        int L, R, C;
        cin >> L >> R >> C;

        if(L+R+C  == 0) break;

        cin.ignore();

        //보드 만들기
        for(int i = 0; i<L; i++){
            for(int j = 0; j<R; j++){
                getline(cin, board[i][j]);
            }
            cin.ignore();
        }
        
        //거리 초기화
        for(int i = 0; i<L; i++){
            for(int j = 0; j<R; j++){
                fill(dist[i][j], dist[i][j] + C, -1);
            }
        }

        //시작지점 찾아서 큐에 넣기
        tuple<int, int, int> start, end;
        queue<tuple<int, int, int>> Q;
        for(int i = 0; i<L; i++){
            for(int j = 0; j<R; j++){
                for(int k = 0; k<C; k++){
                    if(board[i][j][k] == 'S'){
                        Q.push({i,j,k});
                        dist[i][j][k] = 0;
                    }
                }
            }
        }
        
        bool able = false;
        //bfs 시작
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            int curx, cury, curz;
            tie(curx, cury, curz) = cur;
            if(board[curx][cury][curz] == 'E'){
                cout << "Escaped in " << dist[curx][cury][curz] <<" minute(s)."<<"\n";
                able = true;
                break;
            }
            for(int d=0; d<6; d++){
                int px = curx + dx[d];
                int py = cury + dy[d];
                int pz = curz + dz[d];
                if(px < 0 || px >= L) continue;
                if(py < 0 || py >= R) continue;
                if(pz < 0 || pz >= C) continue;
                if(dist[px][py][pz] != -1 or board[px][py][pz] == '#') continue;
                dist[px][py][pz] = dist[curx][cury][curz] + 1;
                Q.push({px, py, pz});
            }
        }

        if(!able){
            cout << "Trapped!" << "\n";
        }
    }
}