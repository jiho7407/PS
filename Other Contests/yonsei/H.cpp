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


ll X, K, C;
ll DP[301][10001];

ll calc(ll ck, ll cx){
    if(cx == 0) return 0;
    if(ck == 0) return cx + C;
    if(DP[ck][cx] != -1) return DP[ck][cx];

    ll &ret = DP[ck][cx] = 1e18;
    rep(i, 1, cx+1){
        ret = min(ret, max(calc(ck, cx-i), calc(ck-1, cx)) + (i+C));
    }
    return ret;
}

void solve(){
    cin >> X >> K >> C;
    rep(i, 0, 301) rep(j, 0, 10001) DP[i][j] = -1;
    cout << calc(K, X) << '\n';

    rep(i, 0, K+1){
        rep(j, 0, X+1) cout << calc(i, j) << ' ';
        cout << '\n';
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