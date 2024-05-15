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

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int R, C;
string board[50];
vector<pii> islands[15];
int island[50][50];
int islandidx = 0;
int dist[15][15];
int DP[15][1<<15];

void bfs(int x, int y){
    queue<pii> q;
    q.push({x, y});
    islands[islandidx].push_back({x, y});
    island[x][y] = islandidx;
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        rep(d, 0, 4){
            int nx = cx + dx[d], ny = cy + dy[d];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] != 'X') continue;
            if(island[nx][ny] != -1) continue;
            q.push({nx, ny});
            islands[islandidx].push_back({nx, ny});
            island[nx][ny] = islandidx;
        }
    }
    islandidx++;
    return;
}

void getdist(int idx1, int idx2){
    int tempdist[50][50];
    rep(i, 0, R) fill(tempdist[i], tempdist[i]+C, -1);
    queue<pii> q;
    for(auto [x, y] : islands[idx1]){
        q.push({x, y});
        tempdist[x][y] = 0;
    }
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        rep(d, 0, 4){
            int nx = cx + dx[d], ny = cy + dy[d];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(island[nx][ny] == idx2){
                dist[idx1][idx2] = tempdist[cx][cy];
                return;
            }
            if(board[nx][ny] != 'S') continue;
            if(tempdist[nx][ny] != -1) continue;
            q.push({nx, ny});
            tempdist[nx][ny] = tempdist[cx][cy] + 1;
        }
    }
    return;
}

void solve(){
    cin >> R >> C;
    rep(i, 0, R) cin >> board[i];
    rep(i, 0, R) fill(island[i], island[i]+C, -1);
    rep(i, 0, R) rep(j, 0, C){
        if(board[i][j] == 'X' && island[i][j] == -1) bfs(i, j);
    }
    // rep(i, 0, R){
    //     rep(j, 0, C) cout << island[i][j] << " ";
    //     cout << "\n";
    // }
    rep(i, 0, islandidx) fill(dist[i], dist[i]+islandidx, 1e8);
    rep(i, 0, islandidx) rep(j, i+1, islandidx){
        getdist(i, j);
        dist[j][i] = dist[i][j];
    }
    // rep(i, 0, islandidx){
    //     rep(j, 0, islandidx) cout << dist[i][j] << " ";
    //     cout << "\n";
    // }
    rep(i, 0, islandidx) fill(DP[i], DP[i]+(1<<islandidx), 1e8);
    rep(i, 0, islandidx) DP[i][1<<i] = 0;
    rep(mask, 1, (1<<islandidx)){
        rep(i, 0, islandidx){
            if(!(mask & (1<<i))) continue;
            rep(j, 0, islandidx){
                if(mask & (1<<j)) continue;
                DP[j][mask|(1<<j)] = min(DP[j][mask|(1<<j)], DP[i][mask] + dist[i][j]);
                rep(k, 0, islandidx){
                    if(!(mask & (1<<k))) continue;
                    DP[j][mask|(1<<j)] = min(DP[j][mask|(1<<j)], DP[i][mask] + dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // rep(i, 0, islandidx){
    //     rep(j, 0, (1<<islandidx)) cout << DP[i][j] << " ";
    //     cout << "\n";
    // }$
    int ans = 1e8;
    rep(i, 0, islandidx) ans = min(ans, DP[i][(1<<islandidx)-1]);
    cout << ans;
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