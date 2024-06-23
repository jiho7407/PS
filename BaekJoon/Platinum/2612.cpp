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
string S, T;
int DP[1001][1001];

void solve(){
    cin >> N >> S >> M >> T;
    fill_n(&DP[0][0], 1001*1001, 0);
    rep(i, 0, N) rep(j, 0, M){
        DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j] - 2);
        DP[i+1][j] = max(DP[i+1][j], DP[i][j] - 2);
        DP[i][j+1] = max(DP[i][j+1], DP[i][j] - 2);
        if(S[i] == T[j]) DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j] + 3);
    }
    // rep(i, 0, N+1) rep(j, 0, M+1) cout << DP[i][j] << " \n"[j==M];
    int mx = -1e9; pii end = {-1, -1};
    rep(i, 1, N+1) rep(j, 1, M+1){
        if(mx < DP[i][j]) mx = DP[i][j], end = {i, j};
    }
    auto [tx, ty] = end;
    pii start;
    while(1){
        // cout << tx << ' ' << ty << '\n';
        if(tx<=0 || ty<=0) break;
        if(DP[tx][ty] == 0) break;
        if(DP[tx][ty-1] - 2 == DP[tx][ty]) ty--;
        else if(DP[tx-1][ty] - 2 == DP[tx][ty]) tx--;
        else if(DP[tx-1][ty-1] + 3 == DP[tx][ty] && S[tx-1] == T[ty-1]){
            start = {tx-1, ty-1};
            tx--, ty--;
        }
        else tx--, ty--;
    }
    auto [sx, sy] = start;
    tx = end.first, ty = end.second;
    // cout << mx << "\n";
    // cout << sx << ' ' << sy << ' ' << tx << ' ' << ty << '\n';
    cout << DP[tx][ty] - DP[sx][sy] << '\n';
    cout << S.substr(sx, tx-sx) << '\n';
    cout << T.substr(sy, ty-sy) << '\n';
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