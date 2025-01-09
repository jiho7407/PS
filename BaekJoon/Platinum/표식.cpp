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

const ll mod = 1234543;

struct Binom{
    vector<ll> fact, invfact;
    ll mod;

    void init(ll P){
        mod = P;
        fact.resize(mod);
        invfact.resize(mod);
        fact[0] = 1;
        for(ll i=1; i<mod; i++) fact[i] = mulmod(fact[i-1], i, mod);
        invfact[mod-1] = invmod(fact[mod-1], mod);
        for(ll i=mod-2; i>=0; i--) invfact[i] = mulmod(invfact[i+1], i+1, mod);
    }

    ll binom(ll n, ll k){
        if(n < k) return 0;
        return mulmod(fact[n], mulmod(invfact[k], invfact[n-k], mod), mod);
    }

    ll Lucas(ll n, ll k){
        if(n < k) return 0;
        if(n == 0 && k == 0) return 1;
        return mulmod(binom(n%mod, k%mod), Lucas(n/mod, k/mod), mod);
    }
}Binom;

void solve(){
    Binom.init(mod);
    int Q; cin >> Q;
    while(Q--){
        ll W, B; cin >> W >> B;
        if(B%2) cout << "odd ";
        else cout << "even ";
        cout << Binom.Lucas(W+B-1, B) << '\n';
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