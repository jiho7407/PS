/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int N; cin >> N;
    string S; cin >> S;
    string T = "PRS";
    int ans = 1e9;
    rep(s, 0, 3){
        int idx = 0, cnt = 0;
        rep(i, 0, N){
            if(S[i] == T[idx]){
                if(idx == 2){
                    idx = 0;
                    cnt++;
                }
                else idx = (idx + 1) % 3;
            }
        }
        ans = min(ans, N - cnt*3);
        T += T[0]; T.erase(T.begin());
    }
    cout << ans << '\n';
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