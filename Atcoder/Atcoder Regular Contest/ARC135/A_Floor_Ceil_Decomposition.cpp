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

const ll mod = 998244353;
map<ll, ll> mp;

ll calc(ll x){
    if(mp.count(x)) return mp[x];
    if(x%2){
        return mp[x] = (calc(x/2) * calc(x/2+1)) % mod;
    }
    else{
        return mp[x] = (calc(x/2) * calc(x/2)) % mod;
    }
}

void solve(){
    ll X; cin >> X;
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    cout << calc(X) << '\n';
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