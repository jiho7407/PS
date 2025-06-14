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

void solve(){
    int N; cin >> N;
    vector<int> DP(N), A(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) DP[i] = 1e9;
    DP[0] = 0;
    rep(i, 0, N){
        rep(j, 1, A[i]+1){
            if(i+j >= N) break;
            DP[i+j] = min(DP[i+j], DP[i]+1);
        }
    }
    if(DP[N-1] == 1e9) cout << -1;
    else cout << DP[N-1];
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