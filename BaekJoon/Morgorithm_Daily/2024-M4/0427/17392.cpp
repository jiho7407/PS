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

int N, M;
int H[1000];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> H[i];
    int s = 0;
    rep(i, 0, N) s += H[i];
    s += N;
    int ans = 0;
    if(M <= s){
        cout << 0;
        return;
    }
    int q = (M - s) / (N+1);
    int r = (M - s) % (N+1);
    rep(i, 0, N+1-r) rep(j, 1, q+1) ans += j*j;
    rep(i, 0, r) rep(j, 1, q+2) ans += j*j;
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