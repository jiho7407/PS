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

ll mu[50001], pfsum[50001];

void precalc(){
    mu[1] = 1;
    rep(i, 1, 50001){
        for(ll j = i*2; j < 50001; j += i){
            mu[j] -= mu[i];
        }
    }

    rep(i, 1, 50001){
        pfsum[i] = pfsum[i-1] + mu[i];
    }
}

void solve(){ 
    ll a, b, d; cin >> a >> b >> d;
    a /= d, b /= d;
    ll ans = 0;
    ll mx = min(a, b);
    for(ll i = 1, j; i<=mx; i=j+1){
        j = min(a/(a/i), b/(b/i));
        // cout << i << ' ' << j << ' ' << pfsum[j] - pfsum[i-1] << ' ' << a/i << ' ' << b/i << '\n';
        ans += (pfsum[j] - pfsum[i-1]) * (a/i) * (b/i);
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    precalc();
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}