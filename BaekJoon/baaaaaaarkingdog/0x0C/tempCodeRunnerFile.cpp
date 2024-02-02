#include <bits/stdc++.h>
using namespace std;

int N, M, G, R;
int board[51][51];
int a[10]; // 0 : Green, 1 : Red, 2 : not using
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int Gvisit[51][51], Rvisit[51][51];
vector<pair<int, int>> ground;

int bfs(queue<pair<int, int>> GQ, queue<pair<int, int>> RQ){
    int flower = 0;
    bool flowermap[51][51];
    for(int i = 0; i<N; i++){
        fill(flowermap[i], flowermap[i]+M, false);
    }
    bool moved = true;
    while(moved){
        queue<pair<int, int>> nextGQ;
        queue<pair<int, int>> nextRQ;
        moved = false;

        while(!GQ.empty()){
            auto c = GQ.front(); GQ.pop();
            // cout << "GQ " << c.first << "," << c.second << " ";
            if(flowermap[c.first][c.second]) continue;
            for(int d = 0; d<4; d++){
                int px = c.first + dx[d];
                int py = c.second + dy[d];
                if(px<0 || px>=N || py<0 || py>=M) continue;
                if(Rvisit[px][py] != -1 || Gvisit[px][py] != -1 || board[px][py] == 0) continue;
                Gvisit[px][py] = Gvisit[c.first][c.second] + 1;
                nextGQ.push({px, py});
                moved = true;
            }
        }
        GQ = nextGQ;
        while(!RQ.empty()){
            auto c = RQ.front(); RQ.pop();
            // cout << "RQ " << c.first << "," << c.second << " ";
            for(int d = 0; d<4; d++){
                int px = c.first + dx[d];
                int py = c.second + dy[d];
                if(px<0 || px>=N || py<0 || py>=M) continue;
                if(Rvisit[px][py] != -1 || board[px][py] == 0) continue;
                if(Gvisit[px][py] == Rvisit[c.first][c.second] + 1){
                    if(Gvisit[px][py] == 0) break;
                    if(flowermap[px][py]) break;
                    flower++;
                    flowermap[px][py] = true;
                    continue;
                }
                if(Gvisit[px][py] != -1) continue;
                Rvisit[px][py] = Rvisit[c.first][c.second] + 1;
                nextRQ.push({px, py});
                moved = true;
            }
        }
        RQ = nextRQ;
    }
    // if(flower == 27){
    //     for(int i=0; i<8; i++){
    //         cout << a[i] << " ";
    //     }
    //     cout << "\n";
    // }
    return flower;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> G >> R;
    int temp;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> temp;
            board[i][j] = temp;
            if(temp == 2) ground.push_back({i, j});
        }
    }
    for(int i = 0; i<ground.size(); i++){
        if(i<G) a[i] = 0;
        else if(i<G+R) a[i] = 1;
        else a[i] = 2;
    }
    int groundSize = ground.size();
    
    int ans = 0;
    do{
        queue<pair<int, int>> greenQ;
        queue<pair<int, int>> redQ;
        for(int i = 0; i<N; i++){
            fill(Gvisit[i], Gvisit[i]+M, -1);
            fill(Rvisit[i], Rvisit[i]+M, -1);
        }
        for(int i = 0; i<groundSize; i++){
            if(a[i] == 0){
                greenQ.push(ground[i]);
                Gvisit[ground[i].first][ground[i].second] = 0;
            }
            else if(a[i] == 1){
                redQ.push(ground[i]);
                Rvisit[ground[i].first][ground[i].second] = 0;
            }
        }
        ans = max(ans, bfs(greenQ, redQ));
    }while(next_permutation(a, a+groundSize));
    cout << ans;
}