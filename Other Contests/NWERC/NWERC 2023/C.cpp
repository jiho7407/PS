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

ll s;

ll calc(ll rsq){
    ll cnt = 0;
    ll x = 1;
    while(x*x < rsq){
        ll ok = 1, ng = 1e5;
        while(ng - ok > 1){
            ll mid = (ok + ng) / 2;
            if(x*x + mid * mid <= rsq) ok = mid;
            else ng = mid;
        }
        cnt += ok;
        x++;
    }
    return cnt*4;
}

void solve(){
    cin >> s;
    ll ok = 1e9, ng = 1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(calc(mid) > s) ok = mid;
        else ng = mid;
    }
    cout << fixed << setprecision(10);
    cout << sqrt((ld)ok) << '\n';
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