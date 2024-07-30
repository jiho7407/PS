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
vector<char> mos = {'A', 'E', 'I', 'O', 'U', 'Y'};
vector<int> mo;
vector<vector<int>> DP; // 끝 자음 개수 0, 1, 2

void solve(){
    cin >> N;
    mo.resize(N, 1e9);
    DP.resize(N+1, vector<int>(3));
    rep(i, 0, N){
        string S; cin >> S;
        rep(j, 0, S.size()){
            if(find(mos.begin(), mos.end(), S[j]) != mos.end()){
                mo[i] = j;
                break;
            }
        }
    }
    rep(i, 0, N+1) rep(j, 0, 3) DP[i][j] = 1e9;
    DP[0][0] = 0;
    rep(i, 0, N){
        rep(j, 0, 3-mo[i]) DP[i+1][0] = min(DP[i+1][0], DP[i][j] + mo[i] + 1);
        rep(j, 0, 2-mo[i]) DP[i+1][0] = min(DP[i+1][0], DP[i][j] + mo[i] + 1);
        DP[i+1][1] = DP[i][0] + 1;
        DP[i+1][2] = DP[i][1] + 1;
    }
    // rep(i, 0, N+1){
    //     rep(j, 0, 3) cout << DP[i][j] << ' ';
    //     cout << '\n';
    // }
    int ans = min({DP[N][0], DP[N][1], DP[N][2]});
    if(ans >= 1e8) cout << '*';
    else cout << ans;
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