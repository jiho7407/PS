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

int N, M;
string S, T;
vector<vector<int>> dp;

bool check(char a, char b){
    if(a == b) return true;
    if(a == 'i' && (b == 'j' || b == 'l')) return true;
    if(a == 'v' && b == 'w') return true;
    return false;
}

void solve(){
    cin >> N >> M;
    cin >> S >> T;
    dp = vector<vector<int>>(N+1, vector<int>(M+1, 0));
    rep(i, 0, N+1) dp[i][0] = i;
    rep(i, 0, M+1) dp[0][i] = i;
    rep(i, 1, N+1){
        rep(j, 1, M+1){
            if(check(S[i-1], T[j-1])) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
        }
    }
    cout << dp[N][M] << '\n';
    // rep(i, 0, N+1){
    //     rep(j, 0, M+1) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
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