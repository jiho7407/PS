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

int N, M;
int A[101];

int calc(int idx, int val, int time){
    if(time == M) return val;
    if(idx == N) return val;
    int ret = val;
    if(idx+1 <= N) ret = max(ret, calc(idx+1, val+A[idx+1], time+1));
    if(idx+2 <= N) ret = max(ret, calc(idx+2, val/2 + A[idx+2], time+1));
    return ret;
}

void solve(){
    cin >> N >> M;
    rep(i, 1, N+1) cin >> A[i];
    cout << calc(0, 1, 0) << '\n';
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