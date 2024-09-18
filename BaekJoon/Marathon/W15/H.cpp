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

ll H, W, L;
ll DP[100][100][4];
string board[100];
ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void solve(){
    cin >> H >> W >> L;
    if(H+W+L == 0) exit(0);

    rep(i, 0, H) cin >> board[i];
    rep(i, 0, H) rep(j, 0, W) fill(DP[i][j], DP[i][j]+4, -1);

    tuple<ll, ll, ll, ll> cur;
    rep(i, 0, H) rep(j, 0, W){
        if(board[i][j] == 'E') cur = {i, j, 0, 0};
        if(board[i][j] == 'S') cur = {i, j, 1, 0};
        if(board[i][j] == 'W') cur = {i, j, 2, 0};
        if(board[i][j] == 'N') cur = {i, j, 3, 0};
    }

    while(L){
        auto [cx, cy, cdir, cdist] = cur;
        // cout << cx+1 << ' ' << cy+1 << '\n';
        if(DP[cx][cy][cdir] != -1){
            ll cycle = cdist - DP[cx][cy][cdir];
            L %= cycle;
            if(L == 0) L += cycle;
        }
        DP[cx][cy][cdir] = cdist;
        ll nx = cx + dx[cdir], ny = cy + dy[cdir];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W || board[nx][ny] == '#'){
            cur = {cx, cy, (cdir+1)%4, cdist};
        }
        else{
            cur = {nx, ny, cdir, cdist+1};
            L--;
        }
    }

    auto [cx, cy, cdir, cdist] = cur;
    cout << cx+1 << ' ' << cy+1 << ' ';
    if(cdir == 0) cout << 'E';
    if(cdir == 1) cout << 'S';
    if(cdir == 2) cout << 'W';
    if(cdir == 3) cout << 'N';
    cout << '\n';
}

int main(){
    fastio();
    while(1) solve();
    return 0;
}