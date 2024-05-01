#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll calc(ll a, ll b, ll c){
    return a*a + b*b + c*c + 7*min({a, b, c});
}

void solve(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(a+b+c+d == 3) {cout << "10\n"; return;}
    cout << max(calc(a+d, b, c), max(calc(a, b+d, c), calc(a, b, c+d))) << '\n';
    return;
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