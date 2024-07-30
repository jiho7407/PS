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

int R, C;
int board[50][50];
bool visited[50][50];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> R >> C;
    rep(i, 0, R) rep(j, 0, C) cin >> board[i][j];
    int ans = 0;
    rep(h, 1, 1001){
        fill_n(&visited[0][0], 50*50, false);
        rep(i, 0, R) rep(j, 0, C){
            if(board[i][j] != h) continue;
            if(visited[i][j]) continue;

            int mnH = 1e9;
            queue<pii> q, cq;
            q.push({i, j}), cq.push({i, j});
            while(!q.empty()){
                auto [cx, cy] = q.front(); q.pop();
                rep(d, 0, 4){
                    int nx = cx + dx[d], ny = cy + dy[d];
                    if(nx < 0 || nx >= R || ny < 0 || ny >= C){ mnH = 0; continue; }
                    if(visited[nx][ny]) continue;
                    if(board[nx][ny] != h){ mnH = min(mnH, board[nx][ny]); continue; }

                    visited[nx][ny] = true;
                    q.push({nx, ny}), cq.push({nx, ny});
                }
            }
            // cout << h << ' ' << mnH << '\n';
            if(mnH <= h) continue;
            while(!cq.empty()){
                auto [cx, cy] = cq.front(); cq.pop();
                ans += mnH - board[cx][cy];
                board[cx][cy] = mnH;
            }
            // rep(i, 0, R){
            //     rep(j, 0, C) cout << board[i][j] << ' ';
            //     cout << '\n';
            // }
        } 
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << ": ";
        solve();
    }
    return 0;
}