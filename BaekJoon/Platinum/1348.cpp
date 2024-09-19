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

int N, M;
string board[50];

map<pii, int> cmp, pmp;
int cidx = 0, pidx = 0;
bool visited[50][50];

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int cost[100][100];

int AM[100], BM[100];
int mvisited[100];

bool dfs(int A, int C){
    if(mvisited[A]) return false;
    mvisited[A] = true;

    rep(B, 0, pidx){
        if(cost[A][B] > C) continue;
        if(BM[B] == -1 || dfs(BM[B], C)){
            AM[A] = B;
            BM[B] = A;
            return true;
        }
    }
    return false;
}

int match(int C){
    int ret = 0;
    fill(AM, AM+cidx, -1);
    fill(BM, BM+pidx, -1);
    rep(A, 0, cidx){
        fill(mvisited, mvisited+cidx, false);
        if(dfs(A, C)) ret++;
    }
    return ret;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];

    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 'C') cmp[{i, j}] = cidx++;
        if(board[i][j] == 'P') pmp[{i, j}] = pidx++;
    }

    if(cidx == 0){
        cout << "0\n";
        return;
    }

    rep(i, 0, cidx) fill(cost[i], cost[i] + pidx, 1e9);
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] != 'C') continue;
        rep(i, 0, N) fill(visited[i], visited[i]+M, false);
        visited[i][j] = true;
        queue<tuple<int, int, int>> q;
        q.push({i, j, 0});
        while(!q.empty()){
            auto [cx, cy, cd] = q.front(); q.pop();
            rep(d, 0, 4){
                int nx = cx + dx[d], ny = cy + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(visited[nx][ny] || board[nx][ny] == 'X') continue;
                visited[nx][ny] = true;
                if(board[nx][ny] == 'P'){
                    cost[cmp[{i, j}]][pmp[{nx, ny}]] = cd+1;
                }
                q.push({nx, ny, cd+1});
            }
        }
    }

    // rep(i, 0, cidx){
    //     rep(j, 0, pidx) cout << cost[i][j] << ' ';
    //     cout << '\n';
    // }

    if(match(10000) != cidx){
        cout << "-1\n";
        return;
    }

    int ok = 5000, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(match(mid) == cidx) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
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