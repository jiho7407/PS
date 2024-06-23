#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int N = 20;
string board[N];
bool visited[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void btr(int cx, int cy, int d){
    if(board[cx][cy] == 'X') return;
    // cout << cx << " " << cy << " " << d << endl;
    // if(d>10) cout << cx << " " << cy << " " << d << endl;

    if(d >= 92){
        cout << "d: " << d << endl;
        rep(i, 0, N){
            rep(j, 0, N){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << '\n' << '\n';
    }
    rep(d1, 0, 4){
        int nx = cx + dx[d1], ny = cy + dy[d1];
        if(nx <= 0 || nx >= N-1 || ny <= 0 || ny >= N-1) continue;
        if(visited[nx][ny]) continue;
        if(board[nx][ny] == 'X') continue;

        int cnt = 0;
        rep(d2, 0, 4){
            int nx2 = nx + dx[d2], ny2 = ny + dy[d2];
            if(nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= N) continue;
            if(visited[nx2][ny2]) cnt++;
        }
        if(cnt > 1) continue;

        visited[nx][ny] = true;
        board[nx][ny] = '.';
        btr(nx, ny, d+1);
        visited[nx][ny] = false;
        board[nx][ny] = '#';
    }
}

void solve(){
    rep(i, 0, N) cin >> board[i];
    fill_n(visited[0], N*N, false);
    board[9][19] = '.';
    btr(9, 19, 1);
    // for(int i = N-1; i >= 0; i--){
    //     cout << "calculating: " << i << endl;
    //     btr(0, i, 1);
    //     btr(i, 0, 1);
    //     btr(N-1, i, 1);
    //     btr(i, N-1, 1);
    // }

    rep(i, 0, N){
        rep(j, 0, N){
            cout << visited[i][j] << " ";
        }
        cout << endl;
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