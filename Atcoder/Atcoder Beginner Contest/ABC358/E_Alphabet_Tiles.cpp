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

const ll MOD = 998244353;
ll F[1001], I[1001];

ll pw(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

ll ncr(ll n, ll r) {
    if(n < r) return 0;
    return F[n] * I[r] % MOD * I[n - r] % MOD;
}

ll K;
ll C[26];
ll DP[27][1001];
const ll mod = 998244353;

void solve(){
    rep(i, 0, 1001) F[i] = I[i] = 1;
    rep(i, 1, 1001) F[i] = F[i - 1] * i % MOD;
    I[1000] = inv(F[1000]);
    for(ll i = 999; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

    cin >> K;
    rep(i, 0, 26) cin >> C[i];
    fill_n(&DP[0][0], 27 * 1001, 0);
    rep(i, 0, 27) DP[i][0] = 1;
    rep(i, 1, 27){
        rep(j, 1, K+1){
            rep(k, 0, min(j, C[i-1])+1){
                DP[i][j] += DP[i-1][j-k] * ncr(j, k) % mod;
                DP[i][j] %= mod;
            }
        }
    }
    // rep(i, 0, 27){
    //     rep(j, 0, K+1) cout << DP[i][j] << " ";
    //     cout << "\n";
    // }
    ll ans = 0;
    rep(i, 1, K+1) ans += DP[26][i];
    cout << ans % mod << "\n";
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