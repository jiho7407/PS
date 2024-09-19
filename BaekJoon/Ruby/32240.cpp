#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
<<<<<<< HEAD
#define rep(i,l,r)for(int i=(l);i<(r);i++)
=======
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
>>>>>>> 925a44fd120d8322361d61e5819d20ff75e8d433
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

<<<<<<< HEAD
const ll mxK = 5e6+1;
const ll mod = 1e9+7;
const ll nmod = 1e10;

struct Xudyh{
    ll mu[mxK], SP[mxK];
    unordered_map<ll, ll> mp[11];

    void init(){
        fill(mu, mu+mxK, 0);
        fill(SP, SP+mxK, 0);
        mu[1] = 1;
        rep(i, 1, mxK){
            for(ll j = i*2; j < mxK; j += i){
                mu[j] -= mu[i];
                if(mu[j] < 0) mu[j] += mod;
            }
            SP[i] = (SP[i-1] + mu[i]*i%mod)%mod;
            if(SP[i] < 0) SP[i] += mod;
        }
    }

    ll ss(ll N){
        N %= mod;
        ll ret = N*(N+1)%mod;
        if(ret&1) return (ret+mod)/2;
        return ret/2;
    }

    ll getSP(ll N){
        if(N < mxK) return SP[N];
        ll q = N/nmod, r = N%nmod;
        if(mp[q].count(r)) return mp[q][r];

        ll ret = 1;
        for(ll i = 2, j; i<=N; i=j+1){
            j = N/(N/i);
            ll tmp = (ss(j) - ss(i-1) + mod)%mod;
            ret -= tmp*getSP(N/i)%mod;
            if(ret < 0) ret += mod;
        }
        return mp[q][r] = ret;
=======

const ll mxK = 1e7+1;
const ll mod = 1e9+7;
struct Xudyh{
    bool is_prime[mxK];
    ll mu[mxK], SF_DP[mxK];
    unordered_map<ll, ll> mp;

    void init(){
        fill(is_prime, is_prime+mxK, 1);
        fill(mu, mu+mxK, 1);
        fill(SF_DP, SF_DP+mxK, 0);
        mu[1] = 1;
        SF_DP[1] = 1;
        rep(i, 2, mxK){
            if(is_prime[i]){
                mu[i] = -1;
                for(ll j = i*2; j<mxK; j+=i){
                    is_prime[j] = 0;
                    mu[j] *= -1;
                }
                ll I = i*i;
                for(ll j = I; j<mxK; j+=I){
                    mu[j] = 0;
                }
            }
            SF_DP[i] = SF_DP[i-1] + mu[i]*i;
            SF_DP[i] %= mod;
            if(SF_DP[i] < 0) SF_DP[i] += mod;
        }
    }

    ll SG(ll N){ // sum of g
        N %= mod;
        ll ret = N*(N+1)%mod;
        if(ret&1) return (ret+mod)/2;
        else return ret/2;
    }

    ll SFG(ll N){ // sum of f*g
        return 1;
    }

    ll SF(ll N){
        if(N < mxK) return SF_DP[N];
        if(mp.find(N) != mp.end()) return mp[N];

        ll ret = SFG(N);
        // SF(N) = (1/g(1))*{SFG(N) - sum(i = 2~N){SF(N/i)*(G(j) - G(i-1))}}
        for(ll i = 2, j; i<=N; i=j+1){
            j = N/(N/i); // 구간: [i, j]
            ll tmp = (SG(j) - SG(i-1)+mod)%mod;
            ret -= tmp*SF(N/i)%mod;
            if(ret < 0) ret += mod;
        }
        return mp[N] = ret;
>>>>>>> 925a44fd120d8322361d61e5819d20ff75e8d433
    }
}Xudyh;

void solve(){ 
    ll N; cin >> N;
    Xudyh.init();

    ll ans = 0;
    for(ll i = 1, j; i<=N; i=j+1){
        ll ni = N/i;
        j = N/ni;
        ni %= mod;
<<<<<<< HEAD
        ll ret = (Xudyh.getSP(j) - Xudyh.getSP(i-1)+mod)%mod;
=======
        ll ret = (Xudyh.SF(j) - Xudyh.SF(i-1)+mod)%mod;
>>>>>>> 925a44fd120d8322361d61e5819d20ff75e8d433
        ret = ret*ni%mod;
        ret = ret*ni%mod;
        ret = ret*(ni+1)%mod;
        ans += ret;
        ans %= mod;
    }   
    cout << ans << '\n';
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