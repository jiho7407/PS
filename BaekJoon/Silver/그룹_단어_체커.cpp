/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
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
    int ans = 0;
    while(N--){
        string S; cin >> S;
        vector<bool> vis(26, false);
        bool flag = true;
        rep(i, 0, S.size()){
            int idx = S[i] - 'a';
            if(vis[idx]){
                flag = false;
                break;
            }
            vis[idx] = true;
            while(i+1 < S.size() && S[i] == S[i+1]) i++;
        }
        if(flag) ans++;
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