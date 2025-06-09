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

int H, W;
int DP[20][20][20][20];
string board[20];

int calc(int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y2) return 0;
    if(DP[x1][y1][x2][y2] != -1) return DP[x1][y1][x2][y2];

    set<int> s;
    rep(i, x1, x2+1) rep(j, y1, y2+1) if(board[i][j] != 'X'){
        int ret = 0;
        ret ^= calc(x1, y1, i-1, j-1);
        ret ^= calc(x1, j+1, i-1, y2);
        ret ^= calc(i+1, y1, x2, j-1);
        ret ^= calc(i+1, j+1, x2, y2);
        s.insert(ret);
    }

    int ret = 0;
    while(s.find(ret) != s.end()) ret++;
    return DP[x1][y1][x2][y2] = ret;
}

void solve(){
    cin >> H >> W;
    rep(i, 0, H) cin >> board[i];
    fill_n(&DP[0][0][0][0], 20*20*20*20, -1);

    if(calc(0, 0, H-1, W-1)) cout << "First";
    else cout << "Second";
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