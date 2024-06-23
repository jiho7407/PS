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
    vector<int> A(N), DP(N);
    rep(i, 0, N) cin >> A[i];
    DP[0] = A[0];
    int ans = DP[0];
    rep(i, 1, N){
        DP[i] = max(DP[i-1] + A[i], A[i]);
        ans = max(ans, DP[i]);
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}