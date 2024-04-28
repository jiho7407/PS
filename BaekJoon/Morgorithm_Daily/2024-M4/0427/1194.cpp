#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
string board[50];
int DP[64][50][50];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    pii start;
    rep(i, 0, N) rep(j, 0, M) if(board[i][j] == '0') start = {i, j};
    rep(i, 0, N) rep(j, 0, M) rep(k, 0, 64) DP[k][i][j] = -1;
    queue<tii> q;
    q.push({start.first, start.second, 0});
    DP[0][start.first][start.second] = 0;
    while(!q.empty()){
        auto [x, y, key] = q.front(); q.pop();
        rep(i, 0, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] == '1'){
                cout << DP[key][x][y] + 1;
                return;
            }
            if(board[nx][ny] >= 'A' && board[nx][ny] <= 'F'){
                int door = board[nx][ny] - 'A';
                if(key & (1 << door)){
                    if(DP[key][nx][ny] == -1){
                        DP[key][nx][ny] = DP[key][x][y] + 1;
                        q.push({nx, ny, key});
                    }
                }
            }
            else if(board[nx][ny] >= 'a' && board[nx][ny] <= 'f'){
                int new_key = key | (1 << (board[nx][ny] - 'a'));
                if(DP[new_key][nx][ny] == -1){
                    DP[new_key][nx][ny] = DP[key][x][y] + 1;
                    q.push({nx, ny, new_key});
                }
            }
            else{
                if(DP[key][nx][ny] == -1){
                    DP[key][nx][ny] = DP[key][x][y] + 1;
                    q.push({nx, ny, key});
                }
            }
        }
    }
    cout << -1;
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}