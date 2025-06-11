/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
int idx[200000], prv[200000], nxt[200000];

bool nonBoring(int L, int R){
    if(L >= R) return true;
    for(int d = 0; L+d <= R-d; d++){
        if(prv[L+d] < L && R < nxt[L+d]){
            return nonBoring(L, L+d-1) && nonBoring(L+d+1, R);
        }
        if(prv[R-d] < L && R < nxt[R-d]){
            return nonBoring(L, R-d-1) && nonBoring(R-d+1, R);
        }
    }
    return false;
}

void solve(){
    // input
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];

    // compression
    vector<int> xs; xs = A;
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    rep(i, 0, N) A[i] = lower_bound(xs.begin(), xs.end(), A[i]) - xs.begin();

    // find prv/nxt
    rep(i, 0, N) idx[i] = -1;
    rep(i, 0, N){
        if(idx[A[i]] != -1) prv[i] = idx[A[i]];
        else prv[i] = -1;
        idx[A[i]] = i;
    }
    rep(i, 0, N) idx[i] = -1;
    rrep(i, N, 0){
        if(idx[A[i]] != -1) nxt[i] = idx[A[i]];
        else nxt[i] = N+1;
        idx[A[i]] = i;
    }

    // rep(i, 0, N) cout << idx[i] << ' ' << prv[i] << ' ' << nxt[i] << '\n';

    // check non-boring
    if(nonBoring(0, N-1)) cout << "non-boring\n";
    else cout << "boring\n";
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}