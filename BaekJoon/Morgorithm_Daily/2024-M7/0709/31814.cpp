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
int A[5000], DP[5000][5000];

ll calc(int i, int j){
    if(i>=N || j>=N) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    if(A[i] <= A[j]) return DP[i][j] = calc(i+1, j+1) + 1;
    else return DP[i][j] = 0;
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    
    fill_n(&DP[0][0], 5000*5000, -1);
    ll ans = 0;
    rep(i, 0, N) rep(j, 0, N) ans += calc(i, j);
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