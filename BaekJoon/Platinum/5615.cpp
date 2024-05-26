#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

lll addmod(lll a, lll b, lll mod){
    return (a%mod + b%mod)%mod;
}

lll mulmod(lll a, lll b, lll mod){
    return (a%mod * b%mod)%mod;
}

lll powmod(lll a, lll b, lll mod){
    lll res = 1;
    while(b){
        if(b&1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool miller_rabin(lll n, lll a){
    lll d = n-1, s = 0;
    while(d%2==0){
        d >>= 1;
        s++;
    }
    if(powmod(a, d, n) == 1) return true;
    rep(i, 0, s){
        if(powmod(a, (1LL<<i)*d, n) == n-1) return true;
    }
    return false;
}

bool isprime(lll n){
    if(n<2) return false;
    else if(n == 2 || n == 3) return true;
    else if(n%2 == 0) return false;
    else if(n<=10000){
        for(lll i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
    }
    else{
        vector<lll> v;
        if(n < 1'373'653) v = {2, 3};
        else if(n < 9'080'191) v = {31, 73};
        else if(n < 4'759'123'141) v = {2, 7, 61};
        else if(n < 1'122'004'669'633) v = {2, 13, 23, 1662803};
        else if(n < 2'152'302'898'747) v = {2, 3, 5, 7, 11};
        else if(n < 3'474'749'660'383) v = {2, 3, 5, 7, 11, 13};
        else if(n < 341'550'071'728'321) v = {2, 3, 5, 7, 11, 13, 17};
        else v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(lll a:v){
            if(!miller_rabin(n, a)) return false;
        }
    }
    return true;
}

ll N, K;

void solve(){
    cin >> N;
    int ans = 0;
    while(N--){
        cin >> K;
        if(isprime(2*K+1)) ans++;
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}