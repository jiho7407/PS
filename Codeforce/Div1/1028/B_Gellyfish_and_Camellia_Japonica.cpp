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

int N, Q;
int B[300000];
vector<tuple<int, int, int>> Qs;

void solve(){
    Qs.clear();

    cin >> N >> Q;
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, Q){
        int x, y, z; cin >> x >> y >> z;
        x--; y--; z--;
        Qs.push_back({x, y, z});
    }

    vector<int> tmp(N);
    rep(i, 0, N) tmp[i] = B[i];
    rrep(i, Q, 0){
        auto [x, y, z] = Qs[i];
        if(x == z) tmp[y] = max(tmp[y], tmp[z]);
        else if(y == z) tmp[x] = max(tmp[x], tmp[z]);
        else{
            tmp[x] = max(tmp[x], tmp[z]);
            tmp[y] = max(tmp[y], tmp[z]);
            tmp[z] = 0;
        }
    }
    vector<int> ret(N);
    rep(i, 0, N) ret[i] = tmp[i];
    for(auto [x, y, z]: Qs) ret[z] = min(ret[x], ret[y]);
    rep(i, 0, N) if(ret[i] != B[i]){
        cout << -1 << "\n";
        return;
    }
    rep(i, 0, N) cout << tmp[i] << " ";
    cout << "\n";
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