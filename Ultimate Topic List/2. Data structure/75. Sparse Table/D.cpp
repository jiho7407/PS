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

int N, Q;
int lg2[100005;]
int SPT[18][100005];


void solve(){ 
    lg2[1] = 0;
    rep(i, 2, 100005) lg2[i] = lg2[i/2]+1;

    cin >> N;
    rep(i, 0, N) cin >> SPT[0][i];
    rep(k, 1, 18) rep(j, 0, N-(1<<k)+1) SPT[k][j] = __gcd(SPT[k-1][j], SPT[k-1][j+(1<<(k-1))]);
    cin >> Q;
    while(Q--){
        int L, R; cin >> L >> R; L--; R--;
        
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