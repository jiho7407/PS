/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int A[5000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    int GCD = __gcd(A[0], A[1]);
    rep(i, 2, N) GCD = __gcd(GCD, A[i]);
    rep(i, 0, N) A[i] /= GCD;

    int cnt = 0;
    rep(i, 0, N) cnt += (A[i] == 1);
    if(cnt){
        cout << N - cnt << '\n';
        return;
    }

    vector<int> dp(5001), ndp(5001);
    rep(i, 1, 5001) dp[i] = 1e9;
    rep(i, 0, N){
        rep(i, 1, 5001) ndp[i] = dp[i];
        ndp[A[i]] = min(ndp[A[i]], 1);
        rep(j, 1, 5001) if(dp[j] < 1e9){
            int G = __gcd(j, A[i]);
            ndp[G] = min(ndp[G], dp[j] + 1);
        }
        swap(dp, ndp);
    }
    cout << (dp[1] - 1) + N - 1 << '\n';
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