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
int board[10][10];

void solve(){
    cin >> H >> W;
    rep(i, 0, H) rep(j, 0, W) cin >> board[i][j];

    while(1){
        bool flag = false;
        rep(i, 0, H) rep(j, 0, W) if(board[i][j]) 
    }
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