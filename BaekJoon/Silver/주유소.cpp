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
    int N; cin >> N;
    vector<ll> dists, costs;
    rep(i, 0, N-1){
        ll a; cin >> a;
        dists.push_back(a);
    }
    rep(i, 0, N){
        ll a; cin >> a;
        costs.push_back(a);
    }
    ll ans = 0;
    ll cur = costs[0];
    rep(i, 0, N-1){
        ans += cur * dists[i];
        cur = min(cur, costs[i+1]);
    }
    cout << ans;
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