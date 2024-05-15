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

void solve(){
    ll T; cin >> T;
    map<ll, ll> m;
    rep(i, 0, T){
        ll x; cin >> x;
        m[x]++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second > T/2){
            cout << it->first << "\n";
            return;
        }
    }
    cout << "SYJKGW\n";
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