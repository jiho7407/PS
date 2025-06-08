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

int N, K, L;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool apple[100][100], snake[100][100];
queue<pii> Q;

void solve(){
    cin >> N;
    cin >> K;
    rep(i, 0, K){
        int x, y; cin >> x >> y; x--; y--;
        apple[x][y] = true;
    }

    cin >> L;
    int t = 0, d = 0;
    Q.push({0, 0});
    snake[0][0] = true;
    rep(i, 0, L){
        int X; char C; cin >> X >> C;
        while(t < X){
            auto [cx, cy] = Q.back();
            int nx = cx + dx[d], ny = cy + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || snake[nx][ny]){
                cout << t+1;
                return;
            }
            Q.push({nx, ny});
            snake[nx][ny] = true;
            if(apple[nx][ny]) apple[nx][ny] = false;
            else{
                auto [tx, ty] = Q.front();
                Q.pop();
                snake[tx][ty] = false;
            }
            t++;
        }
        d = (C == 'L' ? (d+3)%4 : (d+1)%4);
    }
    while(1){
        auto [cx, cy] = Q.back();
        int nx = cx + dx[d], ny = cy + dy[d];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || snake[nx][ny]){
            cout << t+1;
            return;
        }
        Q.push({nx, ny});
        snake[nx][ny] = true;
        if(apple[nx][ny]) apple[nx][ny] = false;
        else{
            auto [tx, ty] = Q.front();
            Q.pop();
            snake[tx][ty] = false;
        }
        t++;
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