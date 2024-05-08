#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, C;
int H[100000];
ll DP[100000][101];

void solve(){
    cin >> N >> C;
    rep(i, 0, N) cin >> H[i];
    rep(i, 0, N) fill(DP[i], DP[i]+101, 1e18);
    rep(i, 0, 101){
        if(i < H[0]) continue;
        DP[0][i] = (i-H[0])*(i-H[0]);
    }
    rep(i, 1, N){
        rep(j, 0, 101){
            if(j < H[i]) continue;
            ll cost = (j-H[i])*(j-H[i]);
            rep(k, 0, 101){
                if(k < H[i-1]) continue;
                DP[i][j] = min(DP[i][j], DP[i-1][k] + cost + C*abs(j-k));
            }
        }
    }
    ll ans = 1e18;
    rep(i, 0, 101) ans = min(ans, DP[N-1][i]);
    cout << ans;
    return;
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