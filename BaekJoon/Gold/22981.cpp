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
    ll N, K; cin >> N >> K;
    vector<ll> v(N);
    rep(i, 0, N) cin >> v[i];
    sort(v.begin(), v.end());
    ll mx = 0;
    rep(i, 1, N){
        mx = max(mx, v[0]*i + v[i]*(N-i));
    }
    cout << (K-1)/mx + 1;
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