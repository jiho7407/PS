#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using namespace std;
 
const int MX = 6000;
const ll MOD = 1000000007;
 
ll fact[MX], invfact[MX];
 
ll modpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
ll modinv(ll a){
    return modpow(a, MOD - 2);
}
 
ll NCR(ll N, ll R){
    if(N < R || R < 0) return 0;
    return (((fact[N] * invfact[R]) % MOD) * invfact[N - R]) % MOD;
}
 
void solve(){
    int N; 
    cin >> N;
    vector<ll> v(N), pos(N, -1);
    rep(i, 0, N){
        cin >> v[i];
        if(v[i] != -1) pos[v[i]] = i;
    }
    vector<int> empt;
    rep(i, 0, N) if(v[i] == -1) empt.push_back(i);
    int m = empt.size();
    ll ans = 0;
 
    int fixmn = N, fixmx = -1;
    int missing = 0;
 
    rep(x, 0, N){
        if(pos[x] != -1){
            fixmn = min(fixmn, (int)pos[x]);
            fixmx = max(fixmx, (int)pos[x]);
        } else{
            missing++;
        }
 
        vector<int> A(m), B(m);
        rep(i, 0, m){
            A[i] = min(empt[i], fixmn) + 1;
            if(empt[i] <= fixmx) B[i] = N - fixmx;
            else B[i] = N - empt[i];
        }

        ll ret = 0;
        if(missing == 0){
            ll tmp = ((ll)fixmn + 1) * (N - fixmx) % MOD;
            ret = tmp * fact[m] % MOD;
        }
        else if(missing == 1){
            ll tmp = 0;
            rep(i, 0, m){
                tmp = (tmp + (ll)A[i] * B[i]) % MOD;
            }
            ret = tmp * fact[m - 1] % MOD;
        }
        else{
            vector<ll> X(m, 0);
            rep(d, 0, m - 1){
                ll sumd = 0;
                rep(i, 0, m-d-1){
                    sumd = (sumd + (ll)A[i] * B[i + d + 1]) % MOD;
                }
                X[d] = sumd;
            }
            ll S2 = 0;
            rep(d, 0, m - 1){
                ll ways = NCR(d, missing - 2);
                S2 = (S2 + ways * X[d]) % MOD;
            }
            ret = S2 * ((fact[missing] * fact[m - missing]) % MOD) % MOD;
        }
 
        ans = (ans + ret) % MOD;
    }
 
    cout << ans % MOD << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    fact[0] = 1;
    rep(i, 1, MX) fact[i] = (fact[i - 1] * i) % MOD;
    invfact[MX - 1] = modpow(fact[MX - 1], MOD - 2);
    for (int i = MX - 2; i >= 0; i--){
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
    
    int tc;
    cin >> tc;
    rep(T, 0, tc){
        solve();
    }
    return 0;
}
