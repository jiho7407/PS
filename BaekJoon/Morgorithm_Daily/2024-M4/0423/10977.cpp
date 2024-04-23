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

void solve(){
    int M, N; cin >> M >> N;
    vector<int> X(N);
    rep(i, 0, N) cin >> X[i];
    vector<int> diff(N);
    rep(i, 0, N-1) diff[i] = X[i+1] - X[i];
    diff[N-1] = X[0] + M - X[N-1];
    vector<int> pi(N, 0);
    pi[0] = 0;
    int j = 0;
    rep(i, 1, N){
        while(j > 0 && diff[i] != diff[j]) j = pi[j-1];
        if(diff[i] == diff[j]) pi[i] = ++j;
    }
    int cut = N - pi[N-1];
    if(N%cut != 0) cut = N;
    int ans = 0;
    rep(i, 0, cut) ans += diff[i];
    cout << ans << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}