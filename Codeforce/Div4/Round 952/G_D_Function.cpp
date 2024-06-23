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

ll addmod(ll a, ll b, ll mod){
    return (a%mod + b%mod)%mod;
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

ll mod = 1e9+7;
int mp[10] = {0, 10, 5, 4, 3, 2, 2, 2, 2, 2};

void solve(){
    ll L, R, K; cin >> L >> R >> K;
    if(K < 10){
        K = mp[K];
        // cout << powmod(K, R, mod) << " " << powmod(K, L, mod) << "\n";
        cout << (powmod(K, R, mod) - powmod(K, L, mod) + mod)%mod << "\n";
    }
    else cout << 0 << "\n";
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}