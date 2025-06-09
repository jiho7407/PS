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

ll N, K;
ll u[4010][4010], DP[801][4001];

void calc(ll idx, ll L, ll R, ll S, ll E){
    if(L>R) return;
    ll mid = (L+R)>>1;
    ll &ret = DP[idx][mid];
    ll opt = -1;
    rep(j, S, min(E, mid)+1){
        ll tmp = DP[idx-1][j-1] + u[j][mid];
        if(ret > tmp){
            ret = tmp;
            opt = j;
        }
    }
    calc(idx, L, mid-1, S, opt);
    calc(idx, mid+1, R, opt, E);
}

void solve(){
    cin >> N >> K;
    rep(i, 1, N+1) rep(j, 1, N+1) cin >> u[i][j];
    rep(c, 1, N+1) for(ll r = c; r>1; r--){
        u[r-1][c] += u[r][c];
    }
    rep(i, 1, N+1) rep(j, i+1, N+1) u[i][j] += u[i][j-1];
    rep(i, 0, K+1) rep(j, 0, N+1) DP[i][j] = 1e18;

    // rep(i, 1, N+1){
    //     rep(j, 1, N+1) cout << u[i][j] << ' ';
    //     cout << '\n';
    // }

    rep(j, 1, N+1) DP[1][j] = u[1][j];
    rep(i, 2, K+1) calc(i, i, N, i, N);

    // rep(i, 1, K+1){
    //     rep(j, 1, N+1) cout << DP[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << DP[K][N];
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