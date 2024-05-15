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

int N, M;
string board[30];
bool visited[30][30];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int bfs(int x, int y){
    queue<pii> q;
    q.push({x, y});
    visited[x][y] = true;
    int cnt = 1;
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] || board[nx][ny] == '*') continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
            cnt++;
        }
    }
    return cnt;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    rep(i, 0, N) fill(visited[i], visited[i]+M, false);
    int ans = -1;
    rep(i, 0, N){
        rep(j, 0, M){
            if(board[i][j] == '*' || visited[i][j]) continue;
            ans = max(ans, bfs(i, j));
        }
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