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

bool cube[5][5][5];

void solve(){
    int N, M; cin >> N >> M;
    rep(i, 0, M){
        int x, y, z; cin >> x >> y >> z;
        x--; y--; z--;
        cube[x][y][z] = 1;
    }
    int ans = 0;
    rep(i, 1, N-1) rep(j, 1, N-1) rep(k, 1, N-1){
        if(!cube[i][j][k]) continue;
        if(!cube[i-1][j][k]) continue;
        if(!cube[i+1][j][k]) continue;
        if(!cube[i][j-1][k]) continue;
        if(!cube[i][j+1][k]) continue;
        if(!cube[i][j][k-1]) continue;
        if(!cube[i][j][k+1]) continue;
        ans++;
    }
    cout << ans;
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