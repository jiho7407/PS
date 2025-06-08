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

ll N, ans;
ll A[500001];
ll prv[500001], nxt[500001];
bool alive[500001];


void solve(){
    cin >> N;
    nxt[0] = 1;
    rep(i, 1, N+1){
        cin >> A[i];
        ans += A[i];
        prv[i] = i-1;
        nxt[i] = i+1;
        alive[i] = true;
    }
    cout << ans << '\n';
    while(1){
        ll x = nxt[0];
        if(prv[x] == 0 && nxt[x] == N+1) break;
        // cout << "x: " << x << endl;
        while(x != N+1){
            ll val = A[x];
            if(prv[x] != 0 && val >= A[prv[x]]){
                alive[prv[x]] = false;
                // cout << x << " kill " << prv[x] << endl;
                if(x == prv[x]) return;
                A[x] += A[prv[x]];
                prv[x] = prv[prv[x]];
                nxt[prv[x]] = x;
            }
            if(nxt[x] != N+1 && val >= A[nxt[x]]){
                alive[nxt[x]] = false;
                // cout << x << " kill " << nxt[x] << endl;
                A[x] += A[nxt[x]];
                nxt[x] = nxt[nxt[x]];
                prv[nxt[x]] = x;
            }
            x = nxt[x];
        }
        // rep(i, 1, N+1) cout << alive[i] << ' ';
        // cout << endl;
    }
    cout << nxt[0] << '\n';
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