#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")

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
        ll ret = (Xudyh.SF(j) - Xudyh.SF(i-1)+mod)%mod;
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