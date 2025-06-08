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
    int a, b, c, d; cin >> a >> b >> c >> d;
    bool color1 = (a%2==0)^(b%2==0), color2 = (c%2==0)^(d%2==0);
    if(color1 == color2) cout << "0\n";
    else cout << "1\n";
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Scenario #" << TC << ":\n";
        solve();
        cout << "\n";
    }
    return 0;
}