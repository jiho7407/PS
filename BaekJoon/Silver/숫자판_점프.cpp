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

set<int> s;
int board[5][5];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void btr(int cnt, int cx, int cy, int num){
    if(cnt == 6){
        s.insert(num);
        return;
    }
    rep(i, 0, 4){
        int nx = cx + dx[i], ny = cy + dy[i];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        btr(cnt+1, nx, ny, num*10 + board[nx][ny]);
    }
}

void solve(){
    rep(i, 0, 5) rep(j, 0, 5) cin >> board[i][j];
    rep(i, 0, 5) rep(j, 0, 5) btr(1, i, j, board[i][j]);
    cout << s.size();
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