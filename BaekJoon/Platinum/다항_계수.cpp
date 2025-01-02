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

// 나머지 연산
const ll MOD = 1e9+9;
ll addmod(ll a, ll b, ll mod){
    return (a%mod + b%mod)%mod;
}

ll submod(ll a, ll b, ll mod){
    return (a%mod - b%mod + mod)%mod;
}

ll mulmod(ll a, ll b, ll mod){
    return (a%mod * b%mod)%mod;
}

ll powmod(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

ll invmod(ll a, ll mod){
    return powmod(a, mod-2, mod);
}

ll divmod(ll a, ll b, ll mod){
    return mulmod(a, invmod(b, mod), mod);
}

ll fact[300000], invfact[300000];

ll NCR(int n, int r){
    if(n < r) return 0;
    return mulmod(fact[n], mulmod(invfact[r], invfact[n-r], MOD), MOD);
}

void solve(){
    fact[0] = 1;
    rep(i, 1, 300000) fact[i] = mulmod(fact[i-1], i, MOD);
    invfact[300000-1] = invmod(fact[300000-1], MOD);
    for(int i=300000-2; i>=0; i--) invfact[i] = mulmod(invfact[i+1], i+1, MOD);

    ll N, M, K; cin >> N >> M >> K;
    ll ans = 0;
    rep(i, 0, (K/(N+1))+1){
        if(i%2 == 0) ans = addmod(ans, mulmod(NCR(M, i), NCR(M + K - i*(N+1) - 1, K - i*(N+1)), MOD), MOD);
        else ans = submod(ans, mulmod(NCR(M, i), NCR(M + K - i*(N+1) - 1, K - i*(N+1)), MOD), MOD);
    }
    cout << ans;
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