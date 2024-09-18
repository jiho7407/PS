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

ll N, K;
vector<ll> C, W, pfsum, cntsum;
vector<vector<ll>> dp;


void solve(){
    cin >> N >> K;
    C.resize(N+1); W.resize(N+1); pfsum.resize(N+1); cntsum.resize(N+1);
    rep(i, 1, N+1) cin >> C[i];
    rep(i, 1, N+1) cin >> W[i];
    pfsum[0] = 0;
    cntsum[0] = 0;
    rep(i, 1, N+1){
        if(C[i] == 1) pfsum[i] = pfsum[i-1] + W[i];
        else pfsum[i] = pfsum[i-1] - W[i];

        if(C[i] == 1) cntsum[i] = cntsum[i-1] + 1;
        else cntsum[i] = cntsum[i-1] - 1;
    }

    dp.resize(2*N+1);

    rep(i, 0, N+1) dp[cntsum[i]+N].push_back(pfsum[i]);

    ll ans = 0;
    rep(i, 0, 2*N+1){
        if(dp[i].empty()) continue;
        dp[i].push_back(-1e18);
        dp[i].push_back(1e18);
        sort(dp[i].begin(), dp[i].end());

        // for(auto x: dp[i]) cout << x << ' ';
        // cout << '\n';
        for(auto x: dp[i]){
            if(x == -1e18 || x == 1e18) continue;
            ll L = x - K, R = x + K;
            ll up = upper_bound(dp[i].begin(), dp[i].end(), R) - dp[i].begin();
            ll lo = lower_bound(dp[i].begin(), dp[i].end(), L) - dp[i].begin();

            ans += up - lo;
            if(L <= x && x <= R) ans--;
        }
        // cout << i << " : " << ans << '\n';
    }
    cout << ans/2 << '\n';

    rep(i, 0, 2*N+1) dp[i].clear();
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