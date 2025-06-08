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

int N;
vector<int> A;

void solve(){
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];

    int mx = INT_MAX;
    rep(i, 0, N){
        int j = lower_bound(A.begin(), A.end(), -A[i]) - A.begin();
        if(j < N && j != i) if(abs(A[i] + A[j]) < abs(mx)) mx = A[i] + A[j];
        if(j > 0 && (j-1) != i) if(abs(A[i] + A[j-1]) < abs(mx)) mx = A[i] + A[j-1];
    }
    cout << mx << '\n';
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