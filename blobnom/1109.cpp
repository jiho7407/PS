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
string board[50];
int island[50][50];
bool visited[50][50], vis2[50][50];
int iidx = 1;

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int par[2500];
vector<int> links[2500];
int depth[2500];

void dfs(int idx){
    depth[idx] = 1;
    for(auto nxt : links[idx]){
        if(depth[nxt] == -1) dfs(nxt);
        depth[idx] = max(depth[idx], depth[nxt]+1);
    }
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];

    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == '.' || visited[i][j]) continue;
        queue<pii> q;
        q.push({i, j});
        visited[i][j] = true;
        island[i][j] = iidx;
        while(!q.empty()){
            auto [cx, cy] = q.front(); q.pop();
            rep(d, 0, 8){
                int nx = cx + dx[d], ny = cy + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(visited[nx][ny] || board[nx][ny] == '.') continue;
                visited[nx][ny] = true;
                island[nx][ny] = iidx;
                q.push({nx, ny});
            }
        }
        iidx++;
    }

    fill(par, par+2500, 1e9);
    rep(i, 0, N) rep(j, 0, M){
        if(island[i][j] == 0) continue;
        if(par[island[i][j]] != 1e9) continue;
        rep(i, 0, N) fill(vis2[i], vis2[i]+M, false);
        queue<pii> q, sea;
        q.push({i, j});
        while(!q.empty()){
            auto [cx, cy] = q.front(); q.pop();
            rep(d, 0, 8){
                int nx = cx + dx[d], ny = cy + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M){
                    par[island[i][j]] = 0;
                    continue;
                }
                if(vis2[nx][ny]) continue;
                vis2[nx][ny] = true;
                if(island[nx][ny] == 0) sea.push({nx, ny});
                else q.push({nx, ny});
            }
        }

        while(!sea.empty()){
            auto [cx, cy] = sea.front(); sea.pop();
            rep(d, 0, 4){
                int nx = cx + dx[d], ny = cy + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M){
                    par[island[i][j]] = 0;
                    continue;
                }
                if(vis2[nx][ny]) continue;
                vis2[nx][ny] = true;
                if(island[nx][ny] != 0) par[island[i][j]] = min(par[island[i][j]], island[nx][ny]);
                else sea.push({nx, ny});
            }
        }
    }

    rep(i, 1, iidx){
        if(par[i] != 0) links[par[i]].push_back(i);
    }

    fill(depth, depth+2500, -1);
    rep(i, 1, iidx) if(depth[i] == -1) dfs(i);

    int ans[2500];
    rep(i, 0, 2500) ans[i] = 0;
    int mx = 0;
    rep(i, 1, iidx) mx = max(mx, depth[i]);
    rep(i, 1, iidx) ans[depth[i]]++;
    // rep(i, 1, iidx) cout << par[i] << ' ';
    // cout << endl;

    if(iidx == 1) cout << -1;
    else{
        rep(i, 1, mx+1) cout << ans[i] << ' ';
    }
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