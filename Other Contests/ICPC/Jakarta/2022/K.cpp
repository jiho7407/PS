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

pll pqmul(pll a, pll b, ll N, ll mod){
    ll p = 0;
    p = addmod(p, mulmod(a.first, mulmod(b.first, N, mod-1), mod-1), mod-1);
    p = addmod(p, mulmod(a.first, b.second, mod-1), mod-1);
    p = addmod(p, mulmod(a.second, b.first, mod-1), mod-1);
    p = addmod(p, a.second*b.second/N, mod-1);

    ll q = a.second*b.second%N;

    return {p, q};
}

pll calc(ll N, ll K, ll mod){
    pll tmp = {0, 2}, res = {0, 1};

    while(K){
        if(K&1){
            res = pqmul(res, tmp, N, mod);
        }
        tmp = pqmul(tmp, tmp, N, mod);
        K >>= 1;
    }

    return res;
}

ll N, K;
ll A[100000];
ll mod = 998244353;

void solve(){
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];

    ll pi = 1;
    rep(i, 0, N) pi = mulmod(pi, A[i], mod);

    pll res = calc(N, K, mod);
    ll pipow = powmod(pi, res.first, mod);

    ll L = 0, R = powmod(2, K, N)-1;
    ll cur = pipow;
    rep(i, L, R+1) cur = mulmod(cur, A[i], mod);
    cout << cur << ' ';

    rep(i, 1, N){
        cur = mulmod(cur, A[(R+1)%N], mod);
        cur = divmod(cur, A[L%N], mod);
        cout << cur << ' ';
        L++, R++;
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