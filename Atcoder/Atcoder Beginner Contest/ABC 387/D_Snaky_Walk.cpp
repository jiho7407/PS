#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

string board[1000];
int dist[1000][1000][2];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve(){
    int H, W; cin >> H >> W;
    rep(i, 0, H) cin >> board[i];

    pii start;
    rep(i, 0, H) rep(j, 0, W) if(board[i][j] == 'S') start = {i, j};

    fill_n(&dist[0][0][0], 1000*1000*2, -1);
    queue<tuple<int, int, int>> q;
    q.push({start.first, start.second, 0});
    q.push({start.first, start.second, 1});
    dist[start.first][start.second][0] = 0;
    dist[start.first][start.second][1] = 0;
    while(!q.empty()){
        auto [x, y, dir] = q.front(); q.pop();
        if(board[x][y] == 'G'){
            cout << dist[x][y][dir];
            return;
        }
        rep(i, 0, 4){
            if(i/2 == dir) continue;
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] == '#') continue;
            if(dist[nx][ny][i/2] != -1) continue;
            dist[nx][ny][i/2] = dist[x][y][dir] + 1;
            q.push({nx, ny, i/2});
        }
    }
    cout << -1;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}