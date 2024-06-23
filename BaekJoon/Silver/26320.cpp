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
    int c, s, d;
    cin >> c >> s >> d;
    d = (d>0);
    if(s > 0) d = 0;
    c += s/2; s %= 2;

    if(c+s == 0) cout << 0 << '\n';
    else if (c == 0) cout << 1 << '\n';
    else cout << c + (d==0) << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Scenario #" << TC << ": ";
        solve();
    }
    return 0;
}