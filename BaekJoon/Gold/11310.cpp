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

int N, M;
vector<string> board;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
map<char, int> ans;
bool visited[1000][1000];

int dist[1000][1000];

void solve(){
    cin >> N >> M;
    rep(i, 0, N){
        string s;
        cin >> s;
        board.push_back(s);
    }
    queue<pii> q;
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 'W'){
            q.push({i, j});
            visited[i][j] = true;
        }
    }
    int lev = 0;
    while(1){
        queue<pii> tmp = q;
        while(!q.empty()){
            auto [cx, cy] = q.front(); q.pop();
            dist[cx][cy] = lev;
            rep(d, 0, 8){
                int nx = cx + dx[d], ny = cy + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(visited[nx][ny]) continue;
                if(board[cx][cy] != board[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
                tmp.push({nx, ny});
            }
        }
        if(tmp.empty()) break;
        while(!tmp.empty()){
            auto [cx, cy] = tmp.front(); tmp.pop();
            rep(d, 0, 8){
                int nx = cx + dx[d], ny = cy + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
                
                if(ans.find(board[nx][ny]) == ans.end()) ans[board[nx][ny]] = lev;
            }
        }
        lev++;
    }
    for(auto [c, cnt] : ans){
        cout << c << ' ' << cnt << '\n';
    }
    // rep(i, 0, N){
    //     rep(j, 0, M){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}