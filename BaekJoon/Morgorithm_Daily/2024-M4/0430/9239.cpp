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

ll tenp[15];

void calc(){
    tenp[0] = 1;
    rep(i, 1, 15){
        tenp[i] = tenp[i-1]*10;
    }

}

void solve(){
    calc();
    double X; cin >> X;
    if(X == 10) {cout << "No solution"; return;}

    ll bot = tenp[5] - (ll)(X*tenp[4]);
    bool pos = 0;
    rep(i, 0, 8){
        ll top = tenp[i+5] - tenp[4];
        rep(j, 1, 10){
            if(top*j%bot) continue;
            ll res = top*j/bot;
            if(to_string(res)[0] != j+'0') continue;
            if(to_string(res).size() != i+1) continue;
            if(res >= tenp[8]) continue;
            cout << res << "\n";
            pos = 1;
        }
    }
    if(!pos) cout << "No solution";
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}