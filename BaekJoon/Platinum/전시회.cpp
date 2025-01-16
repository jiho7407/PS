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

vector<pll> v;

void solve(){
    int N; cin >> N;
    v.resize(N);
    rep(i, 0, N) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    ll mx = 0, ans = -1e18;
    rep(i, 0, N){
        auto [A, B] = v[i];
        ans = max(ans, max(mx + B - A, B));
        mx = max(mx, A) + B;
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