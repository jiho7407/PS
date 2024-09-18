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

int N, M;
string board[40];
bool visited[40][40];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

vector<int> links[1600];
int AM[1600], BM[1600];
bool vis[1600];

int res[40][40];

bool dfs(int a){
    if(vis[a]) return false;
    vis[a] = true;
    for(auto b : links[a]){
        if(BM[b] == -1 || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];

    int ans = 0;

    rep(i, 0, N) rep(j, 0, M){
        if(visited[i][j]) continue;
        if(board[i][j] == 'L'){
            ans++;
            visited[i][j] = true;
            queue<pii> q;
            q.push({i, j});
            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();
                rep(d, 0, 4){
                    int nx = x + dx[d], ny = y + dy[d];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    if(board[nx][ny] == 'L') q.push({nx, ny});
                    if(board[nx][ny] == 'C') board[nx][ny] = 'W';
                }
            }
        }
    }

    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] != 'C') continue;
        ans++;
        if((i+j)%2) continue;
        rep(d, 0, 4){
            int nx = i + dx[d], ny = j + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] != 'C') continue;
            links[i*M+j].push_back(nx*M+ny);
        }
    }

    fill(AM, AM+1600, -1);
    fill(BM, BM+1600, -1);
    rep(i, 0, N*M){
        fill(vis, vis+1600, false);
        if(dfs(i)) ans--;
    }

    cout << ans << '\n';
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