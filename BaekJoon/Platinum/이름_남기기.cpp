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

string S;

void solve(){
    while(cin >> S){
        if(S == "0") break;
        int N = S.size();

        vector<vector<int>> DP(N, vector<int>(1<<N, 1e9));
        rep(i, 0, N) DP[i][1<<i] = min(abs(S[i] - 'A'), 26 - abs(S[i] - 'A')) + 1;
        rep(i, 1, N){
            vector<vector<int>> NDP(N, vector<int>(1<<N, 1e9));
            rep(idx, 0, N) rep(mask, 0, 1<<N){
                if(DP[idx][mask] == 1e9) continue;
                rep(k, 0, N){
                    if(mask & (1<<k)) continue;
                    int nmask = mask | (1<<k);
                    int ncost = min(abs(S[idx] - S[k]), 26 - abs(S[idx] - S[k])) + 1;
                    if(idx < k) rep(l, idx+1, k) ncost += (mask>>l)&1;
                    else rep(l, k, idx+1) ncost += (mask>>l)&1;
                    NDP[k][nmask] = min(NDP[k][nmask], DP[idx][mask] + ncost);
                }
            }
            DP = NDP;
        }
        int ans = 1e9;
        rep(i, 0, N) ans = min(ans, DP[i][(1<<N)-1]);
        cout << ans << '\n';
    }
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