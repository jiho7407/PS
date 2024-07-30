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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

pll extended_gcd(ll a, ll b){
    if(b == 0) return {1, 0};
    pll t = extended_gcd(b, a%b);
    return {t.second, t.first - t.second * (a/b)};
}

void solve(){
    ll R, S, Q;
    cin >> R >> S >> Q;
    S *= -1;
    ll G = gcd(R, S);
    pll ans = extended_gcd(R, S);
    ll x = ans.first, y = ans.second;
    x *= Q/G, y *= Q/G;
    ll a = R/G, b = S/G;
    
    if(x <= 0){
        ll tmp = abs(x)/b + 1;
        x += tmp*b;
        y -= tmp*a;
    }

    ll tmp = (x-1)/abs(b);
    x -= tmp*b;
    y += tmp*a;

    if(y >= 0){
        ll tmp = abs(y)/a + 1;
        x += tmp*b;
        y -= tmp*a;
    }
    cout << x << " " << -y << "\n";
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}