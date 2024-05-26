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
    ll N, T; cin >> N >> T;
    vector<ll> V;
    vector<pii> xtoidx;
    rep(i, 0, N){
        ll x, v;
        cin >> x >> v;
        xtoidx.push_back({x, i});
        V.push_back(x+v*T);
    }
    sort(xtoidx.begin(), xtoidx.end());
    sort(V.begin(), V.end());
    ll ansidx;
    rep(i, 0, N){
        if(xtoidx[i].second == 0){
            ansidx = i;
            break;
        }
    }
    cout << V[ansidx] << '\n';
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