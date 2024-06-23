#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
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
    vector<ll> cross(N), left(N), right(N);
    rep(i, 0, N) cin >> cross[i];
    rep(i, 1, N) cin >> left[i];
    rep(i, 0, N-1) cin >> right[i];
    rep(i, 1, N) left[i] += left[i-1];
    for(int i = N-2; i >= 0; i--) right[i] += right[i+1];
    ll ans = 0, mx = 1e18;
    rep(i, 0, N){
        if(cross[i] + left[i] + right[i] < mx){
            mx = cross[i] + left[i] + right[i];
            ans = i;
        }
    }
    cout << ans+1 << " " << mx << '\n';
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