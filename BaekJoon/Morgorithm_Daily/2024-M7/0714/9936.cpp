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

const int mINF = -2e9;
int N, K;
int board[1010][3];
int DP[3030][1010][1<<3]; // N, K, state

int calc(int n, int k, int state){
    if(k == K) return 0;
    if(n >= N*3) return mINF;
    if(DP[n][k][state] != mINF) return DP[n][k][state];

    if(state & 1) return DP[n][k][state] = calc(n+1, k, state>>1);

    // 오른쪽으로 두기
    if((n%3) != 2 && !(state & 2)) DP[n][k][state] = max(DP[n][k][state], calc(n+2, k+1, (state>>2)) + board[n/3][n%3] + board[n/3][n%3+1]);
    // 아래로 두기
    if(n < 3*(N-1)){
        int nxtstate = (state >> 1) + (1 << 2);
        DP[n][k][state] = max(DP[n][k][state], calc(n+1, k+1, nxtstate) + board[n/3][n%3] + board[n/3+1][n%3]);
    }
    // 아무것도 두지 않기
    DP[n][k][state] = max(DP[n][k][state], calc(n+1, k, state>>1));

    return DP[n][k][state];
}

void solve(){
    cin >> N >> K;
    rep(i, 0, N) rep(j, 0, 3) cin >> board[i][j];
    fill_n(&DP[0][0][0], 3030*1010*(1<<3), mINF);
    cout << calc(0, 0, 0) << '\n';
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