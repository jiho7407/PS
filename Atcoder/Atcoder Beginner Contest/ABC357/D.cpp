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

lll addmod(lll a, lll b, lll mod){
    return (a%mod + b%mod)%mod;
}

lll mulmod(lll a, lll b, lll mod){
    return (a%mod * b%mod)%mod;
}

lll powmod(lll a, lll b, lll mod){
    lll res = 1;
    while(b){
        if(b&1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res%mod;
}

ll invmod(ll a, ll mod){
    return powmod(a, mod-2, mod);
}

ll N;
ll mod = 998244353;
ll ans = 0;

void solve(){
    cin >> N;
    ll tmp = N;
    ll r = 1;
    while(tmp){
        r = mulmod(r, 10, mod);
        tmp /= 10;
    }
    ll inv = invmod(r-1, mod);
    ll ans = (N%mod) * (powmod(r, N, mod)-1) % mod * inv % mod;
    cout << ans << endl;
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