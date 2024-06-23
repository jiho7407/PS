#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int H = 105, W = 105;
int N;
int sx, sy, ex, ey;
bool board[H][W];
int dist[H][W][4];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> sx >> sy >> ex >> ey;
    cin >> N;
    fill_n(&board[0][0], H*W, false);
    while(N--){
        int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
        cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y >> p4x >> p4y;
        if(p1x == p2x){
            if(p1y > p2y){ // ㄴ자형 (오른쪽 위 빔)
                rep(i, p2x, p4x) rep(j, p2y, p1y) board[i][j] = true;
                rep(i, p4x, p3x) rep(j, p3y, p4y) board[i][j] = true;
            }
            else{ // 역 ㄱ자형 (왼쪽 아래 빔)
                rep(i, p4x, p2x) rep(j, p1y, p2y) board[i][j] = true;
                rep(i, p3x, p4x) rep(j, p4y, p3y) board[i][j] = true;
            }
        }
        else{
            if(p1x > p2x){ // 오른쪽 아래 빔
                rep(i, p3x, p4x) rep(j, p3y, p1y) board[i][j] = true;
                rep(i, p4x, p1x) rep(j, p4y, p1y) board[i][j] = true;
            }
            else{
                rep(i, p4x, p3x) rep(j, p1y, p3y) board[i][j] = true;
                rep(i, p1x, p4x) rep(j, p1y, p4y) board[i][j] = true;
            }
        }
    }

    fill_n(&dist[0][0][0], H*W*4, 10000);
    queue<tuple<int, int, int, int>> q, tq; // x, y, cnt, dir
    rep(i, 0, 4){
        dist[sx][sy][i] = 0;
        q.push({sx, sy, 0, i});
    }
    while(1){
        if(q.empty()) break;
        while(!q.empty()){
            auto [x, y, cnt, dir] = q.front(); q.pop();
            if(dist[x][y][dir] < cnt) continue;
            if(x == ex && y == ey) continue;
            rep(d, 0, 4){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                // 장애물 로직
                if(d==0 && y-1 >= 0 && board[x-1][y-1] && board[x-1][y]) continue;
                if(d==1 && y-1 >= 0 && board[x][y-1] && board[x][y]) continue;
                if(d==2 && x-1 >= 0 && board[x-1][y-1] && board[x][y-1]) continue;
                if(d==3 && x-1 >= 0 && board[x-1][y] && board[x][y]) continue;

                if(d == dir){
                    if(dist[nx][ny][d] > cnt){
                        dist[nx][ny][d] = cnt;
                        q.push({nx, ny, cnt, d});
                    }
                }
                else{
                    if(dist[nx][ny][d] > cnt + 1){
                        dist[nx][ny][d] = cnt + 1;
                        tq.push({nx, ny, cnt + 1, d});
                    }
                }
            }
        }
        swap(q, tq);
    }

    int ans = 1e9;
    rep(i, 0, 4) ans = min(ans, dist[ex][ey][i]);
    cout << ans << '\n';

    // rep(i, 1, H){
    //     rep(j, 1, W) cout << board[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // rep(i, 1, H){
    //     rep(j, 1, W) cout << dist[i][j][1] << ' ';
    //     cout << '\n';
    // }
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