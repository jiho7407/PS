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


ll X, K, C;
ll DP[301][10001];

void solve(){
    cin >> X >> K >> C;
    rep(i, 1, X+1) DP[0][i] = i + C;
    rep(i, 1, K+1){
        set<pair<ll, int>> st;
        rep(j, 1, X+1){
            if(j == 1){
                DP[i][j] = DP[i-1][j] + DP[0][1];
                st.insert({DP[i][j], j});
                continue;
            }
            auto it = st.lower_bound({DP[i-1][j], -1});
            auto [ret, idx] = *it;
            DP[i][j] = ret + (j - idx) + C;
            st.insert({DP[i][j], j});
        }
    }
    rep(i, 0, K+1){
        rep(j, 0, X+1) cout << DP[i][j] << ' ';
        cout << '\n';
    }
    cout << DP[K][X];
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