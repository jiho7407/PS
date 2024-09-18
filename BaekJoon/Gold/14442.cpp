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

int N, M, K;
int DP[11][1000][1000];
string board[1000];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N) cin >> board[i];
    fill_n(&DP[0][0][0], 11*1000*1000, -1);
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    DP[0][0][0] = 1;
    while(!q.empty()){
        auto [x, y, k] = q.front(); q.pop();
        // cout << x << ' ' << y << ' ' << k << '\n';
        if(x == N-1 && y == M-1){
            cout << DP[k][x][y];
            return;
        }
        rep(d, 0, 4){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            int nk = k + (board[nx][ny] == '1');
            if(nk > K) continue;
            if(DP[nk][nx][ny] != -1) continue;
            DP[nk][nx][ny] = DP[k][x][y] + 1;
            q.push({nx, ny, nk});
        }
    }
    cout << -1;
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