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
string S;
int DP[100][100];

void solve(){
    cin >> N >> S;
    fill_n(&DP[0][0], 100 * 100, 9);
    rep(i, 0, N) DP[i][i] = 1;
    rep(i, 1, N) rep(j, 0, N-i){
        int x = j, y = j+i;
        if(S[x] == S[y]) DP[x][y] = min(DP[x+1][y], DP[x][y-1]);
        else DP[x][y] = min(DP[x+1][y], DP[x][y-1]) + 1;

        if(S[x+1] == S[x]) DP[x][y] = min(DP[x][y], DP[x+1][y]);
        if(S[y-1] == S[y]) DP[x][y] = min(DP[x][y], DP[x][y-1]);

        rep(k, x, y) DP[x][y] = min(DP[x][y], DP[x][k] + DP[k+1][y]);
    }
    cout << DP[0][N-1] << '\n';

    // rep(i, 0, N) rep(j, 0, N) cout << DP[i][j] << " \n"[j==N-1];
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