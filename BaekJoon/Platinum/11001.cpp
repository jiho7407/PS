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

const int mxN = 1e5;
int N, D;
ll T[mxN], V[mxN];
ll DP[mxN], K[mxN];

void DnC(ll s, ll e, ll l, ll r){
    if(s>e) return;

    ll m = (s+e)>>1;
    DP[m] = 0;

    rep(i, max(l, m-D), min(e, r)+1){
        ll ret = T[m]*(m-i) + V[i];
        if(DP[m]<ret){
            DP[m] = ret;
            K[m] = i;
        }
    }

    DnC(s, m-1, l, K[m]);
    DnC(m+1, e, K[m], r);
}

void solve(){
    cin >> N >> D;
    rep(i, 0, N) cin >> T[i];
    rep(i, 0, N) cin >> V[i];
    DnC(0, N-1, 0, N-1);
    ll ans = 0;
    rep(i, 0, N) ans = max(ans, DP[i]);
    cout << ans;
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