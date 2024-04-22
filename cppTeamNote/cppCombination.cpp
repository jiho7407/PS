#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define debug1 puts("--@111%--")
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")
#define y1 ysgjowiaef
using namespace std;

#define INF 2123456789
 
const ll MOD = 1e9 + 7;

// a^b
// !IMPORTANT : a must be lower then 2e32
ll pw(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

// 1/x % MOD
// !IMPORTANT : x must be lower then 2e32
ll inv(ll x) { return pw(x, MOD - 2); }

// nCr
ll ncr(ll n, ll r) {
    if(n < r) return 0;
    return F[n] * I[r] % MOD * I[n - r] % MOD;
}