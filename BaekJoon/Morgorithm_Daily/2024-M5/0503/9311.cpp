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
string board[15];
bool visited[15][15];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void solve(){
    cin >> N >> M;
    rep(i, 0, N) fill(visited[i], visited[i]+M, false);
    rep(i, 0, N) cin >> board[i];
    pii S;
    rep(i, 0, N) rep(j, 0, M) if(board[i][j] == 'S') S = {i, j};
    queue<tuple<int, int, int>> q;
    q.push({S.first, S.second, 0});
    visited[S.first][S.second] = true;
    while(!q.empty()){
        auto [cx, cy, ct] = q.front(); q.pop();
        if(board[cx][cy] == 'G'){
            cout << "Shortest Path: " << ct << '\n';
            return;
        }
        rep(i, 0, 4){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] || board[nx][ny] == 'X') continue;
            visited[nx][ny] = true;
            q.push({nx, ny, ct+1});
        }
    }
    cout << "No Exit\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}