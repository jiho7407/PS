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
int board[250][250];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    int ans = 0;
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 0) continue;
        ans++;
        queue<pii> q;
        q.push({i, j});
        board[i][j] = 0;
        while(!q.empty()){
            pii cur = q.front(); q.pop();
            rep(k, 0, 8){
                int nx = cur.first + dx[k], ny = cur.second + dy[k];
                if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                if(board[nx][ny] == 0) continue;
                q.push({nx, ny});
                board[nx][ny] = 0;
            }
        }
    }
    cout << ans;
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