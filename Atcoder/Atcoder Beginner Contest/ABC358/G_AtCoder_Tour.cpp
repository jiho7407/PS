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

ll H, W, K;
pll start;
ll board[50][50];

const ll INF = 1e18;
ll DP[3000][50][50];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> H >> W >> K;
    ll si, sj; cin >> si >> sj;
    start = {si-1, sj-1};
    rep(i, 0, H) rep(j, 0, W) cin >> board[i][j];

    fill_n(&DP[0][0][0], 3000*50*50, -INF);
    DP[0][start.first][start.second] = 0;
    ll ans = 0;
    rep(t, 0, min(K, H*W)+1){
        rep(i, 0, H) rep(j, 0, W){
            ans = max(ans, DP[t][i][j] + (K-t)*board[i][j]);
            rep(d, 0, 4){
                ll ni = i + dx[d], nj = j + dy[d];
                if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                DP[t+1][ni][nj] = max(DP[t+1][ni][nj], DP[t][i][j] + board[ni][nj]);
            }
        }
    }
    cout << ans << '\n';
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