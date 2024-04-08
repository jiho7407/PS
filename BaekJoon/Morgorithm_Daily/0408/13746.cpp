#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
vector<string> board;
int ans = 0;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        for(int d = 0; d < 4; d++){
            int px, py;
            px = cx + dx[d];
            py = cy + dy[d];
            if(px < 0 || py < 0 || px >= N || py >= M) continue;
            if(board[px][py] == 'W') continue;
            board[px][py] = 'W';
            q.push({px, py});
        }
    }
}

void solve(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == 'L'){
                ans++;
                BFS(i, j);
            }
        }
    }
    cout << ans << '\n';
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}