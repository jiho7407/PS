#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef tuple<ll, int, int> tlii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
ll board[300][300];
ll cost[300][300];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == -2) board[i][j] = 0;
        else if(board[i][j] == -1) board[i][j] = 1e18;
    }

    priority_queue<tlii, vector<tlii>, greater<tlii>> pq;
    rep(i, 0, N) rep(j, 0, M) cost[i][j] = 1e18;
    
    //왼쪽, 아랫쪽 변 넣기
    rep(i, 1, N){
        pq.push({board[i][0], i, 0});
        cost[i][0] = board[i][0];
    }
    rep(i, 1, M){
        pq.push({board[N-1][i], N-1, i});
        cost[N-1][i] = board[N-1][i];
    }

    while(!pq.empty()){
        auto [c, x, y] = pq.top(); pq.pop();
        if(cost[x][y] < c) continue;
        rep(i, 0, 8){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            ll nc;
            if(board[nx][ny] == -2) nc = 0;
            else if(board[nx][ny] == -1) nc = 1e18;
            else nc = board[nx][ny];

            ll mc = nc + c;
            if(cost[nx][ny] > mc){
                cost[nx][ny] = mc;
                pq.push({mc, nx, ny});
            }
        }
    }

    ll ans = 1e18;
    // 오른쪽, 윗쪽 변
    rep(i, 0, N){
        ans = min(ans, cost[i][M-1]);
    }
    rep(i, 0, M){
        ans = min(ans, cost[0][i]);
    }
    if (ans == 1e18) cout << -1;
    else cout << ans;
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