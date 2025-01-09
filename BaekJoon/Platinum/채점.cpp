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

const int MXSCR = 1132500;
int N, scr[150], K;
int sum[150][150];
bitset<MXSCR+2> DP[151], DPN[151];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> scr[i];
    cin >> K;

    rep(i, 0, N){
        sum[i][i] = scr[i];
        rep(j, i+1, N){
            sum[i][j] = sum[i][j-1] + scr[j];
        }
    }

    DP[0][0] = 1;
    rep(i, 0, N){
        rep(j, 0, i+1){
            DPN[j+1] |= DP[j] << sum[i-j][i];
            DPN[0] |= DP[j];
        }
        rep(j, 0, i+2){
            DP[j] = DPN[j];
            DPN[j].reset();
        }
    }

    bitset<MXSCR+2> ans;
    rep(i, 0, N+1) ans |= DP[i];
    while(K <= MXSCR && ans[K] == 1) K++;
    cout << K;
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