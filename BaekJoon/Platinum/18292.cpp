#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M, K;
ll board[10][10];
ll DP[12][52][1<<10];

bool isOk(int x){
    rep(i, 0, M) if(x&(1<<i) && x&(1<<(i+1))) return false;
    return true;
}

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N)rep(j, 0, M)cin >> board[i][j];
    fill_n(DP[0][0], 12*52*(1<<10), -1e18);
    DP[0][0][0] = 0;
    rep(i, 0, N) rep(j, 0, K+1) rep(k, 0, 1<<M){
        if(!isOk(k)) continue;
        rep(t, 0, 1<<M){
            if(!isOk(t)) continue;
            if(k&t) continue;
            ll nk = j + __builtin_popcount(t);
            if(nk > K) continue;
            ll newget = 0;
            rep(c, 0, M) if(t&(1<<c)) newget += board[i][c];
            DP[i+1][nk][t] = max(DP[i+1][nk][t], DP[i][j][k] + newget);
        }
    }
    ll ans = -1e18;
    rep(i, 0, 1<<M) ans = max(ans, DP[N][K][i]);
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