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

const int mod = 1e9+7;
int DP[100000][10]; // DP[i][j]: i번째 자리까지 체크, j로 끝남

void solve(){
    int N; cin >> N;
    fill_n(&DP[0][0], 100000*10, 0);
    rep(i, 1, 10) DP[0][i] = 1;
    rep(i, 1, N){
        rep(j, 0, 10){
            rep(k, j, 10){
                DP[i][j] += DP[i-1][k];
                DP[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    rep(i, 0, 10){
        ans += DP[N-1][i];
        ans %= mod;
    }
    cout << ans+1 << '\n';
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