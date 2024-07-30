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

int N, M, K;
pii srt, ed;
string board[1000];
int DP[1000][1000];

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N) cin >> board[i];
    cin >> srt.first >> srt.second >> ed.first >> ed.second;
    srt.first--; srt.second--; ed.first--; ed.second--;
    fill_n(&DP[0][0], 1000*1000, -1);
    queue<pii> q;
    q.push(srt);
    DP[srt.first][srt.second] = 0;
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        if(cx == ed.first && cy == ed.second) break;
        rep(d, 0, 4){
            rep(k, 1, K+1){
                int nx = cx + dx[d]*k, ny = cy + dy[d]*k;
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
                if(board[nx][ny] == '#') break;
                if(DP[nx][ny] != -1 && DP[nx][ny] <= DP[cx][cy]) break;
                if(DP[nx][ny] != -1) continue;
                DP[nx][ny] = DP[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << DP[ed.first][ed.second] << '\n';
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