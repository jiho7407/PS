#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int C, D, M;
int stock[51][11];
int mxprofit[500010];

void solve(){
    cin >> C >> D >> M;
    rep(i, 0, C) rep(j, 0, D) cin >> stock[i][j];
    rep(i, 1, D){
        rep(j, 0, M+1) mxprofit[j] = j;
        rep(c, 0, C){
            rep(j, stock[c][i-1], M+1){
                mxprofit[j] = max(mxprofit[j], mxprofit[j-stock[c][i-1]] + stock[c][i]);
            }
        }    
        M = mxprofit[M];
    }
    cout << M << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}