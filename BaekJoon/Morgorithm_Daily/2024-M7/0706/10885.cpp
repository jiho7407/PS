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

ll mod = 1e9+7;
ll A[100000];

void solve(){
    int N; cin >> N;
    rep(i, 0, N) cin >> A[i];
    ll ans = -1;
    ll ret1 = 0, ret2 = 0;
    bool pls1 = 1, pls2 = 1;
    bool on1 = 0, on2 = 0;
    rep(i, 0, N){
        if(A[i] == 0){
            ret1 = 0;
            ret2 = 0;
            on1 = 0;
            on2 = 0;
            pls1 = 1;
            pls2 = 1;
            continue;
        }
        if(!on1) on1 = 1;
        if(on1){
            ret1 += abs(A[i])/2;
            if(A[i] < 0) pls1 ^= 1;
            if(pls1) ans = max(ans, ret1);
        }
        if(on2){
            ret2 += abs(A[i])/2;
            if(A[i] < 0) pls2 ^= 1;
            if(pls2) ans = max(ans, ret2);
        }
        if(!on2 && A[i] < 0) on2 = 1;
        // cout << ret1 << ' ' << ret2 << ' ' << ans << '\n';
    }
    if(ans == -1){ cout << 0 << '\n'; return; }
    ll ret = 1;
    rep(i, 0, ans) ret = (ret*2)%mod;
    cout << ret << '\n';
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