#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int R, C;
int board[1000][1000];
bool visited[1000][1000];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


void solve(){
    cin >> R >> C;
    rep(i, 0, R) rep(j, 0, C) cin >> board[i][j];
    int ans = 0;
    queue<pii> q;
    rep(i, 0, R) rep(j, 0, C){
        if(visited[i][j] || board[i][j] == 0) continue;
        q.push({i, j});
        visited[i][j] = true;
        while(!q.empty()){
            auto [cx, cy] = q.front(); q.pop();
            rep(d, 0, 8){
                int nx = cx + dx[d], ny = cy + dy[d];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(visited[nx][ny] || board[nx][ny] == 0) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        ans++;
    }
    cout << ans << '\n';
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