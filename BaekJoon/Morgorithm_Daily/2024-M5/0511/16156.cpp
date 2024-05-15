#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll, ll> tiii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M;
ll board[500][500];
ll dist[500][500];
ll from[500][500];
ll dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    ll ans[500];
    fill(ans, ans+500, 0);
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq; // dist, x, y, from
<<<<<<< HEAD
    rep(i, 0, N) fill(dist[i], dist[i]+N, 1e9);
    rep(i, 0, N) fill(from[i], from[i]+N, -1);
=======
    rep(i, 0, N) fill(dist[i], dist[i]+M, 1e18);
    rep(i, 0, N) fill(from[i], from[i]+M, -1);
>>>>>>> fd713e931550eb0dbf5e9263bfc2efcf44772dc2
    rep(i, 0, N){
        pq.push({board[i][M-1], i, M-1, i});
        dist[i][M-1] = board[i][M-1];
        from[i][M-1] = i;
    }
    while(!pq.empty()){
        auto [d, x, y, f] = pq.top(); pq.pop();
        if(dist[x][y] < d) continue;
        if(y == 0){
            ans[f]++;
        }
        rep(i, 0, 4){
            ll nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(from[nx][ny] != -1) continue;
            if(dist[nx][ny] > d + board[nx][ny]){
                dist[nx][ny] = d + board[nx][ny];
                from[nx][ny] = f;
                pq.push({d + board[nx][ny], nx, ny, f});
            }
        }
    }
    rep(i, 0, N) cout << ans[i] << '\n';
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}