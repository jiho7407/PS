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

int W, H;
string board[1500];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // up, right, down, left
int pfsum1[1501][1501], pfsum2[1501][1501], pfsum3[1501][1501];

int get_sum(int x1, int y1, int len, int (&pfsum)[1501][1501]){
    int x2 = x1 + len, y2 = y1 + len;
    return pfsum[x2][y2] - pfsum[x1][y2] - pfsum[x2][y1] + pfsum[x1][y1];
}

void solve(){
    cin >> W >> H;
    rep(i, 0, H) cin >> board[i];

    // wall
    rep(i, 0, H) rep(j, 0, W) if(board[i][j] == '#') pfsum1[i+1][j+1] = 1;

    // left-hand rule
    pii cur = {0, 0};
    int dir = 0;
    while(1){
        pfsum2[cur.first+1][cur.second+1] = 1;
        if(cur.first == H-1 && cur.second == W-1) break;
        dir = (dir+3)%4;
        while(1){
            int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
            if(nx<0 || nx>=H || ny<0 || ny>=W || board[nx][ny] == '#') dir = (dir+1)%4;
            else {
                cur = {nx, ny};
                break;
            }
        }
    }

    // right-hand rule
    cur = {0, 0};
    dir = 3;
    while(1){
        pfsum3[cur.first+1][cur.second+1] = 1;
        if(cur.first == H-1 && cur.second == W-1) break;
        dir = (dir+1)%4;
        while(1){
            int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
            if(nx<0 || nx>=H || ny<0 || ny>=W || board[nx][ny] == '#') dir = (dir+3)%4;
            else {
                cur = {nx, ny};
                break;
            }
        }
    }

    pfsum1[1][1] = pfsum1[H][W] = 1;
    pfsum2[1][1] = pfsum2[H][W] = 0;
    pfsum3[1][1] = pfsum3[H][W] = 0;
    
    // rep(i, 0, H){
    //     rep(j, 0, W) cout << pfsum3[i+1][j+1] << ' ';
    //     cout << '\n';
    // }

    rep(i, 0, H){
        rep(j, 0, W){
            pfsum1[i+1][j+1] += pfsum1[i][j+1] + pfsum1[i+1][j] - pfsum1[i][j];
            pfsum2[i+1][j+1] += pfsum2[i][j+1] + pfsum2[i+1][j] - pfsum2[i][j];
            pfsum3[i+1][j+1] += pfsum3[i][j+1] + pfsum3[i+1][j] - pfsum3[i][j];
        }
    }

    int mn = 1e9;
    pii ans = {-1, -1};

    rep(i, 0, H) rep(j, 0, W){
        if(board[i][j] == '#') continue;
        int ok = 1, ng = min(H-i, W-j) + 1;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            if(get_sum(i, j, mid, pfsum1)) ng = mid;
            else ok = mid;
        }

        if(!get_sum(i, j, ok, pfsum2) || !get_sum(i, j, ok, pfsum3)) continue;
        ng = 0;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(get_sum(i, j, mid, pfsum2) && get_sum(i, j, mid, pfsum3)) ok = mid;
            else ng = mid;
        }

        if(ok < mn){
            mn = ok;
            ans = {i+1, j+1};
        }
    }
    if(mn == 1e9) cout << "Impossible";
    else cout << mn << ' ' << ans.second << ' ' << ans.first;
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

/*
7 6
.......
.#.....
.....##
#......
#......
.......
*/