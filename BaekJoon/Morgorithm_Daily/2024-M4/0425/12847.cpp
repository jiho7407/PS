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
ll T[100001];

void solve(){
    cin >> N >> M;
    vector<int> arr(N);
    rep(i, 0, N) cin >> arr[i];
    ll window = 0;
    ll ans = 0;
    rep(i, 0, M) window += arr[i];
    ans = window;
    rep(i, M, N){
        window += arr[i];
        window -= arr[i-M];
        ans = max(ans, window);
    }
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