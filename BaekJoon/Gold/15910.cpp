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
int DP[100001][7];

void solve(){
    cin >> S; N = S.size();
    fill_n(&DP[0][0], 100000*7, 1000000);
    DP[0][0] = 0;
    rep(i, 1, N+1){
        DP[i][1] = min({DP[i-1][0]+(S[i-1]!='B'),
                        DP[i-1][1]+(S[i-1]!='B'),
                        DP[i-1][6]+(S[i-1]!='B')});
        DP[i][2] = DP[i-1][1] + (S[i-1]!='A');
        DP[i][3] = DP[i-1][2] + (S[i-1]!='N');
        DP[i][4] = DP[i-1][3] + (S[i-1]!='A');
        DP[i][5] = min({DP[i-1][4] + (S[i-1]!='N'),
                        DP[i-1][6] + (S[i-1]!='N')});
        DP[i][6] = DP[i-1][5] + (S[i-1]!='A');
    }
    cout << DP[N][6];
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