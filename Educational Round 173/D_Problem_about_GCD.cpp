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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    ll L, R, G; cin >> L >> R >> G;

    ll LL = ((L-1)/G+1);
    ll RR = R/G;

    ll sub = 0;
    bool flag = false;
    while(true){
        rep(i, 0, sub+1){
            ll nL = LL + i;
            ll nR = RR - (sub - i);
            if(nL > nR) break;
            if(gcd(nL, nR) == 1){
                cout << nL*G << ' ' << nR*G << '\n';
                flag = true;
                break;
            }
        }
        if(flag) break;
        if(LL+sub > RR) break;
        sub++;
    }

    if(!flag) cout << -1 << ' ' << -1 << '\n';
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