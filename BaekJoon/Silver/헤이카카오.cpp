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

void solve(){
    ld a, d, k; cin >> a >> d >> k;
    ld ans = 0;
    ld cp = 1;

    int cnt = 1;
    while(d < 100){
        ld cur = d/100;
        ans += cp*cur*cnt*a;
        cp *= (1-cur);
        d *= 1 + k/100;
        cnt++;
    }
    ans += cp*cnt*a;
    cout << fixed << setprecision(10) << ans;
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