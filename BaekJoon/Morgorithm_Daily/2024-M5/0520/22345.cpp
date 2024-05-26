#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 2e5;
int N, Q;
vector<pll> town, pf, sf;

void solve(){
    cin >> N >> Q;
    rep(i, 0, N){
        ll a, x; cin >> a >> x;
        town.push_back({x, a});
    }
    sort(town.begin(), town.end());
    pf.push_back({0, 0});
    rep(i, 0, N){
        pf.push_back({pf.back().first + town[i].second, pf.back().second + town[i].first * town[i].second});
    }
    sf.push_back({0, 0});
    for(int i = N-1; i >= 0; i--){
        sf.push_back({sf.back().first + town[i].second, sf.back().second + town[i].first * town[i].second});
    }
    reverse(sf.begin(), sf.end());
    while(Q--){
        ll x; cin >> x;
        auto it = lower_bound(town.begin(), town.end(), make_pair(x, 0LL)) - town.begin();
        ll ans = 0;
        ans += x*pf[it].first - pf[it].second;
        ans += sf[it].second - x*sf[it].first;
        cout << ans << '\n';
    }
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