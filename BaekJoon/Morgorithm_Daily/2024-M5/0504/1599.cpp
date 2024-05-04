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

int N, M, K;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
map<char, int> dir = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
string board[100];
int dp[100][100][1<<8], treasure[100][100];

void solve(){
    while(1){
        cin >> N >> M;
        if(N+M == 0) break;
        rep(i, 0, N) cin >> board[i];
        cin >> K;
        rep(i, 0, N) fill(treasure[i], treasure[i]+M, 0);
        rep(i, 0, K){
            int x, y;
            cin >> x >> y;
            treasure[x-1][y-1] = 1<<i;
        }
        rep(i, 0, N) rep(j, 0, M) fill(dp[i][j], dp[i][j]+(1<<K), 1e9);
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> q; // dist, x, y, treasure
        q.push({0, 0, 0, 0});
        dp[0][0][0] = 0;
        while(!q.empty()){
            auto [cd, cx, cy, ct] = q.top(); q.pop();
            if(dp[cx][cy][ct] < cd) continue;
            rep(d, 0, 4){
                int nd = cd + d;

                int ndir = (dir[board[cx][cy]] + nd) % 4;
                int nx = cx + dx[ndir], ny = cy + dy[ndir];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                int nt = ct | treasure[nx][ny];
                if(dp[nx][ny][nt] > nd+1){
                    dp[nx][ny][nt] = nd+1;
                    q.push({nd+1, nx, ny, nt});
                }
            }
        }
        cout << dp[N-1][M-1][((1<<K)-1)] << '\n';
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