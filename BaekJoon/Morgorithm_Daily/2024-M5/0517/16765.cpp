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

ll N, K;
ll A[10000], DP[10001];

void solve(){
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    fill_n(DP, 10001, 0);
    rep(i, 1, N+1){
        ll mx = 0;
        rep(j, 0, K){
            if(i-j-1 < 0) break;
            mx = max(mx, A[i-j-1]);
            DP[i] = max(DP[i], DP[i-j-1]+mx*(j+1));
        }
    }
    cout << DP[N] << '\n';
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