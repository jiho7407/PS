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
string board[100];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

const int mxA = 10000, mxB = 10000;
int AM[mxA], BM[mxB];
bool visited[mxA], visited2[mxB];
vector<int> links[mxA], rev_links[mxB];

bool dfs(int A){
    if(visited[A]) return false;
    visited[A] = true;
    for(int B : links[A]){
        if(BM[B] == -1 || dfs(BM[B])){
            AM[A] = B;
            BM[B] = A;
            return true;
        }
    }
    return false;
}

bool dfs2(int A){ // A를 포함하지 않는 매칭을 찾을 수 있는지 확인
    if(visited[A]) return false;
    visited[A] = true;
    if(AM[A] == -1) return true;
    for(int nA : rev_links[AM[A]]){
        if(dfs2(nA)) return true;
    }
    return false;
}

bool dfs3(int B){ // B를 포함하지 않는 매칭을 찾을 수 있는지 확인
    if(visited2[B]) return false;
    visited2[B] = true;
    if(BM[B] == -1) return true;
    for(int nB : links[BM[B]]){
        if(dfs3(nB)) return true;
    }
    return false;    
}

void solve(){
    cin >> N >> M;
    if(N+M == 0) exit(0);
    rep(i, 0, N) cin >> board[i];
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 'X') continue;
        int a = i*M + j;
        if((i+j)%2 == 0){
            rep(d, 0, 4){
                int nx = i + dx[d], ny = j + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 'X') continue;
                int b = nx*M + ny;
                links[a].push_back(b);
                rev_links[b].push_back(a);
            }
        }
    }
    fill(AM, AM+mxA, -1);
    fill(BM, BM+mxB, -1);
    int match = 0;
    rep(i, 0, N*M){
        int cx = i/M, cy = i%M;
        if((cx+cy)%2 == 1 || board[cx][cy] == 'X') continue;
        fill(visited, visited+mxA, false);
        if(dfs(i)) match++;
    }
    // cout << match << '\n';

    rep(i, 0, N){
        rep(j, 0, M){
            if(board[i][j] == 'X'){ cout << 'X'; continue; }
            if((i+j)%2 == 0){
                int A = i*M + j;
                fill(visited, visited+mxA, false);
                if(AM[A] == -1 || dfs2(A)) cout << 'B';
                else cout << 'A';
            }
            else{
                int B = i*M + j;
                fill(visited2, visited2+mxB, false);
                if(BM[B] == -1 || dfs3(B)) cout << 'B';
                else cout << 'A';
            }
        }
        cout << '\n';
    }
    cout << '\n';

    rep(i, 0, N*M){
        links[i].clear();
        rev_links[i].clear();
    }
}

int main(){
    fastio();
    int tc = 1e9;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}