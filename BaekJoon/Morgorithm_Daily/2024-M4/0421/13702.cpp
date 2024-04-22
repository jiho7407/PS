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

ll N, M;
ll mak[10000];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> mak[i];
    ll ok = 1, ng = 1e12;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        rep(i, 0, N) cnt += mak[i]/mid;
        if(cnt>=M) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
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