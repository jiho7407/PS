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

struct Binom{
    vector<ll> fact, invfact;
    ll N, mod;

    void init(ll n, ll p){
        N = n;
        mod = p;
        fact.resize(N);
        invfact.resize(N);
        fact[0] = 1;
        for(ll i=1; i<N; i++) fact[i] = mulmod(fact[i-1], i, mod);
        invfact[N-1] = invmod(fact[N-1], mod);
        for(ll i=N-2; i>=0; i--) invfact[i] = mulmod(invfact[i+1], i+1, mod);
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
    ll D; cin >> D;
    vector<ll> W(D+1);
    rep(i, 0, D+1) cin >> W[i];
    ll Q; cin >> Q;
    Binom.init(1050000, 1000000007);
    while(Q--){
        ll V, N; cin >> V >> N;
        ll ans = 0;
        rep(i, 0, D+1){
            if(D - V*i < 0) break;
            ll tmp = mulmod(Binom.binom(N+i-1, i), W[D - V*i], 1000000007);
            if(i%2) ans = submod(ans, tmp, 1000000007);
            else ans = addmod(ans, tmp, 1000000007);
        }
        cout << ans << '\n';
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