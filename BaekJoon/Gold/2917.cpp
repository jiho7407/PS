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

int N, M;
string board[500];
int dist[500][500];
bool visited[500][500];

pii start, ed;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool bfs(int k){
    auto [sx, sy] = start;
    if(dist[sx][sy] < k) return false;
    auto [ex, ey] = ed;
    fill_n(&visited[0][0], 500*500, false);
    queue<pii> q;
    q.push(start);
    visited[sx][sy] = true;
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        if(cx == ex && cy == ey) return true;
        rep(d, 0, 4){
            int nx = cx + dx[d], ny = cy + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] || dist[nx][ny] < k) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return false;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    queue<pair<pii, int>> q;
    fill_n(&dist[0][0], 500*500, 1e9);
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 'V') start = {i, j};
        if(board[i][j] == 'J') ed = {i, j};
        if(board[i][j] == '+'){
            q.push({{i, j}, 0});
            dist[i][j] = 0;
        }
    }
    while(!q.empty()){
        auto [cur, curd] = q.front(); q.pop();
        auto [cx, cy] = cur;
        rep(d, 0, 4){
            int nx = cx + dx[d], ny = cy + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] <= curd+1) continue;
            dist[nx][ny] = curd+1;
            q.push({{nx, ny}, curd+1});
        }
    }
    int ok = 0, ng = 1000;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        if(bfs(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
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