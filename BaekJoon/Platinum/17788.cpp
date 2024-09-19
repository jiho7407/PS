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

ll N, M, K;
string board[20];
ll dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
bool visited[150][150];

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N) cin >> board[i];
    queue<pll> q;
    rep(i, 0, N) rep(j, 0, M) if(board[i][j] == '#'){
        q.push({50+i, 50+j});
        visited[50+i][50+j] = true;
    }

    if(q.empty()){
        cout << 0;
        return;
    }

    rep(k, 0, min((ll)30, K)){
        queue<pll> nq;
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            rep(i, 0, 8){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= 150 || ny < 0 || ny >= 150 || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                nq.push({nx, ny});
            }
        }
        swap(q, nq);
    }
    if(K <= 30){
        int ans = 0;
        rep(i, 0, 150) rep(j, 0, 150) if(visited[i][j]) ans++;
        cout << ans;
    }
    else{
        ll ans = 0;
        ll lx = 1e9, rx = -1e9, ly = 1e9, ry = -1e9;
        rep(i, 0, 150) rep(j, 0, 150) if(visited[i][j]){
            lx = min(lx, i);
            rx = max(rx, i);
            ly = min(ly, j);
            ry = max(ry, j);
        }
        ll empty = 0;
        rep(i, lx, rx+1) rep(j, ly, ry+1) if(!visited[i][j]) empty++;
        ll area = ((rx+K-30) - (lx-K+30) + 1) * ((ry+K-30) - (ly-K+30) + 1);
        cout << area - empty;
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