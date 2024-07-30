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
    ll L, R; cin >> L >> R;
    ll mod, ret; cin >> mod >> ret;
    if(L > R) swap(L, R);
    mod = abs(mod);
    if(ret < 0 || ret >= mod){
        cout << "Unknwon Number";
        return;
    }

    ll ans;
    if(L>=0) ans = (L/mod)*mod + ret;
    else ans = (L/mod - 1)*mod + ret;
    if(ans < L) ans += mod;

    if(ans > R) cout << "Unknwon Number";
    else if(ans + mod <= R) cout << "Unknwon Number";
    else cout << ans;
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