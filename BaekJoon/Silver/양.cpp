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

int R, C;
string board[250];
bool visited[250][250];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve(){
    cin >> R >> C;
    rep(i, 0, R) cin >> board[i];
    int Sheep = 0, Wolf = 0;
    rep(i, 0, R) rep(j, 0, C){
        if(visited[i][j] || board[i][j] == '#') continue;
        bool isOut = false;
        queue<pii> q;
        q.push({i, j});
        visited[i][j] = true;
        int sheep = board[i][j] == 'o', wolf = board[i][j] == 'v';
        while(!q.empty()){
            auto [cx, cy] = q.front(); q.pop();
            rep(k, 0, 4){
                int nx = cx + dx[k], ny = cy + dy[k];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C){
                    isOut = true;
                    continue;
                }
                if(visited[nx][ny] || board[nx][ny] == '#') continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
                if(board[nx][ny] == 'o') sheep++;
                if(board[nx][ny] == 'v') wolf++;
            }
        }
        if(isOut) continue;
        if(sheep > wolf) Sheep += sheep;
        else Wolf += wolf;
    }
    cout << Sheep << ' ' << Wolf;
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