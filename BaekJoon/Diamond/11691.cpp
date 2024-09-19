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

const ll mxN= 1e6+1;
const ll mod = 1e9+7;
ll N;
ll pi[mxN], val[mxN], pfsum[mxN];

// 나머지 연산
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

void solve(){
    rep(i, 1, mxN){
        pi[i] += i;
        for(int j = 2*i; j < mxN; j += i){
            pi[j] -= pi[i];
        }
    }
    rep(i, 2, mxN){
        val[i] = mulmod(mulmod(i, i, mod), pi[i], mod);
        val[i] = divmod(val[i], 2, mod);
        pfsum[i] = addmod(pfsum[i-1], val[i], mod);
    }

    cin >> N;
    ll ans = 0;
    rep(i, 1, N+1){
        ans = addmod(ans, mulmod(i, pfsum[N/i], mod), mod);
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