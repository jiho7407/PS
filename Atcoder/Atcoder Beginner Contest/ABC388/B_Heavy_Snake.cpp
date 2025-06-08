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
    int N, D; cin >> N >> D;
    vector<pii> v(N);
    rep(i, 0, N) cin >> v[i].first >> v[i].second;
    rep(k, 1, D+1){
        int mx = -1;
        rep(i, 0, N) mx = max(mx, v[i].first * (v[i].second + k));
        cout << mx << '\n';
    }
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