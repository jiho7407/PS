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

int N;
vector<int> D, V;

void solve(){
    cin >> N;
    D.resize(N); V.resize(N);
    rep(i, 0, N) cin >> D[i] >> V[i];
    int ans = 0;
    int played = 0, downloaded = V[0];
    ans = max(ans, downloaded);
    rep(i, 1, N){
        played += D[i-1]; downloaded += V[i];
        ans = max(ans, downloaded-played);
    }
    cout << ans << '\n';
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