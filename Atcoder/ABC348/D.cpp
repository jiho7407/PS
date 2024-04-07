#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int H, W, M;
vector<string> board;
vector<vector<int>> medicine;
vector<vector<int>> dp;
pair<int, int> start;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> H >> W;
    for(int i=0; i<H; i++){
        string s;
        cin >> s;
        board.push_back(s);
        for(int j=0; j<W; j++){
            if(s[j] == 'S') start = {i, j};
        }
    }
    medicine.resize(H, vector<int>(W, 0));
    dp.resize(H, vector<int>(W, -1));
    cin >> M;
    for(int i=0; i<M; i++){
        int r, c, e;
        cin >> r >> c >> e;
        medicine[r-1][c-1] = e;
    }
    queue<tuple<int, int, int>> PQ;
    PQ.push({medicine[start.first][start.second], start.first, start.second});
    dp[start.first][start.second] = medicine[start.first][start.second];
    while(!PQ.empty()){
        auto [energy, cx, cy] = PQ.front(); PQ.pop();
        if(dp[cx][cy] > energy) continue;
        if(energy == 0) continue;
        for(int d = 0; d<4; d++){
            int px = cx + dx[d], py = cy + dy[d];
            if(px < 0 || px >= H || py < 0 || py >= W) continue;
            if(board[px][py] == '#') continue;
            if(board[px][py] == 'T'){
                cout << "Yes" << '\n';
                return;
            }
            int next_energy = max(energy - 1, medicine[px][py]);
            if(dp[px][py] >= next_energy) continue;
            dp[px][py] = next_energy;
            PQ.push({next_energy, px, py});
        }
    }
    cout << "No" << '\n';
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}