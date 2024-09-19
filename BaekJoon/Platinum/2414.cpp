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
int Hboard[50][50], Vboard[50][50];
int Hidx = 0, Vidx = 0;

int AM[2000], BM[2000];
vector<int> Alinks[2000];
int visited[2000];

bool dfs(int A){
    if(visited[A]) return false;
    visited[A] = true;

    for(auto B: Alinks[A]){
        if(BM[B] == -1 || dfs(BM[B])){
            AM[A] = B;
            BM[B] = A;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];

    fill_n(&Hboard[0][0], 50*50, -1);
    fill_n(&Vboard[0][0], 50*50, -1);

    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == '.') continue;
        if(Hboard[i][j] != -1) continue;
        int jj = j;
        while(jj < M && board[i][jj] == '*'){
            Hboard[i][jj] = Hidx;
            jj++;
        }
        Hidx++;
    }

    rep(j, 0, M) rep(i, 0, N){
        if(board[i][j] == '.') continue;
        if(Vboard[i][j] != -1) continue;
        int ii = i;
        while(ii < N && board[ii][j] == '*'){
            Vboard[ii][j] = Vidx;
            ii++;
        }
        Vidx++;
    }

    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == '.') continue;
        Alinks[Hboard[i][j]].push_back(Vboard[i][j]);
    }

    fill(AM, AM+2000, -1);
    fill(BM, BM+2000, -1);
    int cnt = 0;
    rep(i, 0, Hidx){
        fill(visited, visited+2000, false);
        if(dfs(i)) cnt++;
    }
    cout << cnt;
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