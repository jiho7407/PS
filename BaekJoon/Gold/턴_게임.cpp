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
    ll X, Y; cin >> X >> Y;
    ll ok = 1e7, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(mid * (mid+1) / 2 >= X+Y) ok = mid;
        else ng = mid;
    }
    if(ok * (ok+1) / 2 != X+Y){
        cout << -1 << endl;
        return;
    }
    ll cur = ok;
    int ans = 0;
    while(X){
        ans++; 
        if(cur >= X) break;
        X -= cur--;
    }
    cout << ans << endl;
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