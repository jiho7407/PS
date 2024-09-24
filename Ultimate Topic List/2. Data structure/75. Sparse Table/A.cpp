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

int N, M;
int lg2[200001];
int sparse[20][200001];


void solve(){ 
    fill_n(lg2, 200001, 0);
    rep(i, 2, 200001) lg2[i] = lg2[i/2]+1;
    
    cin >> N >> M;
    fill_n(&sparse[0][0], 20*200001, 1e9);
    rep(i, 0, N) cin >> sparse[0][i];
    rep(i, 1, 20) rep(j, 0, N-1){
        if(j+(1<<i) > N) break;
        sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
    }

    while(M--){
        int L, R; cin >> L >> R;
        L--; R--;
        int k = lg2[R-L+1];
        cout << min(sparse[k][L], sparse[k][R-(1<<k)+1]) << '\n';
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