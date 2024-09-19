#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")

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
        ll ret = (Xudyh.getSP(j) - Xudyh.getSP(i-1)+mod)%mod;
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