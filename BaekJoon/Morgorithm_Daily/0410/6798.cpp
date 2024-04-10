#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int sx, sy, ex, ey;
int visited[8][8];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void solve(){
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;
    for(int i = 0; i<8; i++) fill(visited[i], visited[i]+8, -1);
    queue<pii> q;
    q.push({sx, sy});
    visited[sx][sy] = 0;
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        if(cx == ex && cy == ey){
            cout << visited[cx][cy];
            return;
        }
        for(int d = 0; d<8; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            if(visited[nx][ny] != -1) continue;
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
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