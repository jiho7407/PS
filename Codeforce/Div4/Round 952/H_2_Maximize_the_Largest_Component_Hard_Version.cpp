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

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int N, M;
vector<string> board;
vector<vector<bool>> visited;
vector<int> rmx, cmx;
vector<vector<int>> pmx;

void solve(){
    // 입력받기
    cin >> N >> M;
    board.resize(N);
    rep(i, 0, N) cin >> board[i];

    // 초기화작업
    rmx.resize(N, 0);
    cmx.resize(M, 0);
    pmx.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<bool>(M, false));

    // bfs로 그룹 나누기
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == '.') rmx[i]++, cmx[j]++, pmx[i][j]++;
        if(board[i][j] == '.' || visited[i][j]) continue;
        int sz = 0;
        queue<pii> q; q.push({i, j});
        set<int> rpos, cpos;
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            rpos.insert(x), cpos.insert(y);
            if(visited[x][y]) continue;
            visited[x][y] = true;
            if(board[x][y] == '.') continue;
            sz++;
            rep(d, 0, 4){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                q.push({nx, ny});
            }
        }
        for(auto x: rpos) rmx[x] += sz;
        for(auto y: cpos) cmx[y] += sz;
        for(auto x: rpos) for(auto y: cpos) pmx[x][y] += sz;
    }

    int ans = 0;
    rep(i, 0, N) rep(j, 0, M){
        ans = max(ans, rmx[i] + cmx[j] - pmx[i][j]);
    }

    cout << ans << '\n';

    // 초기화작업
    rmx.clear();
    cmx.clear();
    pmx.clear();
    visited.clear();
    board.clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}