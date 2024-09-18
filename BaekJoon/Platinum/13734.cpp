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

int N, M, sz;
string board[50];
string S;
map<char, int> mp = {{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int DP[50][50][51];
pii stt, edd;

pii move(pii P, int idx){
    int nx = P.first + dx[idx], ny = P.second + dy[idx];
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) return P;
    if(board[nx][ny] == '#') return P;
    return {nx, ny};
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    cin >> S;
    sz = S.size();

    fill_n(&DP[0][0][0], 50*50*51, 1e9);
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 'S' || board[i][j] == 'R') stt = {i, j};
        if(board[i][j] == 'G' || board[i][j] == 'E') edd = {i, j};
    }

    deque<tuple<int, pii, int>> q;
    q.push_back({0, stt, 0});
    DP[stt.first][stt.second][0] = 0;
    while(!q.empty()){
        auto [cost, P, idx] = q.front(); q.pop_front();
        auto [cx, cy] = P;

        if(DP[cx][cy][idx] < cost) continue;
        // cout << cx << ' ' << cy << ' ' << idx << ' ' << DP[cx][cy][idx] << '\n';

        // 명령을 추가하는 경우
        rep(i, 0, 4){
            pii nxt = move(P, i);
            if(DP[nxt.first][nxt.second][idx] > cost+1){
                DP[nxt.first][nxt.second][idx] = cost+1;
                q.push_back({cost+1, nxt, idx});
            }
        }

        if(idx >= sz) continue;

        // 명령을 따르는 경우
        pii nxt = move(P, mp[S[idx]]);
        if(DP[nxt.first][nxt.second][idx+1] > cost){
            DP[nxt.first][nxt.second][idx+1] = cost;
            q.push_front({cost, nxt, idx+1});
        }

        // 명령을 삭제하는 경우
        if(DP[cx][cy][idx+1] > cost+1){
            DP[cx][cy][idx+1] = cost+1;
            q.push_back({cost+1, P, idx+1});
        }
    }

    int ans = 1e9;
    rep(i, 0, sz+1) ans = min(ans, DP[edd.first][edd.second][i]);
    cout << ans;
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