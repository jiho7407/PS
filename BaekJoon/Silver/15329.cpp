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

ll L, K;
ll W[101], B[101];

void solve(){
    cin >> L >> K;
    B[1] += 1;
    B[K] += 1;
    rep(i, 2, L+1){
        W[i] += B[i-1];
        B[i] += W[i-1];
        if(i-K >= 0) B[i] += W[i-K];
    }

    ll ans = 0;
    rep(i, 0, L+1) ans += B[i];
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