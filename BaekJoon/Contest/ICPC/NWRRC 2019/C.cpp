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

int N = 0, W, H;
string board[100];

vector<tuple<int, int, bool>> links[101][101]; // y, x, used
bool printed = false;


void dfs(int y, int x, bool cross){
    for(auto &link: links[y][x]){
        auto [ny, nx, used] = link;
        if(used) continue;
        if(cross && (nx == x || ny == y)) continue;
        if(!cross && (nx != x && ny != y)) continue;
        link = {ny, nx, true};
        dfs(ny, nx, !cross);
    }
    if(!printed){
        printed = true;
        return;
    }
    cout << x << ' ' << y << '\n';
}

void solve(){
    cin >> W >> H;
    rep(i, 0, H) cin >> board[i];
    rep(i, 0, H) rep(j, 0, W){
        if(board[i][j] != 'X') continue;
        N++;
        // 대각선 '\'
        links[i][j].push_back({i+1, j+1, false});
        links[i+1][j+1].push_back({i, j, false});

        // 대각선 '/'
        links[i][j+1].push_back({i+1, j, false});
        links[i+1][j].push_back({i, j+1, false});

        // 왼쪽 '|'
        links[i][j].push_back({i+1, j, false});
        links[i+1][j].push_back({i, j, false});

        // 오른쪽 '|'
        links[i][j+1].push_back({i+1, j+1, false});
        links[i+1][j+1].push_back({i, j+1, false});
    }
    
    cout << 4*N - 1 << '\n';
    bool flag = false;
    rep(i, 0, H+1) rep(j, 0, W+1){
        if(flag) break;
        if(links[i][j].empty()) continue;
        dfs(i, j, true);
        flag = true;
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