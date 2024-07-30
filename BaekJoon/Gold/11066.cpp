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

int N;
int A[500], pfsum[501];
int DP[500][500];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    pfsum[0] = 0;
    rep(i, 1, N+1) pfsum[i] = pfsum[i-1] + A[i-1];
    fill_n(&DP[0][0], 500*500, 1e9);
    rep(i, 0, N) DP[i][i] = 0;
    rep(i, 1, N){
        rep(j, 0, N-i){
            int k = j+i;
            rep(l, j, k){
                DP[j][k] = min(DP[j][k], DP[j][l] + DP[l+1][k] + pfsum[k+1] - pfsum[j]);
            }
        }
    }
    cout << DP[0][N-1] << '\n';
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