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

void solve(){
    ll x, y, z, k; cin >> x >> y >> z >> k;
    ll ans = 0;
    rep(a, 1, x+1) rep(b, 1, y+1){
        ll tmp = a*b;
        if(tmp > k || k%tmp) continue;
        ll c = k/tmp;
        ll ret = max(0LL, x-a+1)*max(0LL, y-b+1)*max(0LL, z-c+1);
        ans = max(ans, ret);
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}