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

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int N, M;
string board[20];
set<pair<pii, pii>> visited;

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    pii Apos, Bpos;
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 'A') Apos = {i, j};
        if(board[i][j] == 'B') Bpos = {i, j};
    }
    queue<tuple<pii, pii, int>> q;
    visited.insert({Apos, Bpos});
    q.push({Apos, Bpos, 0});
    while(!q.empty()){
        auto [A, B, cnt] = q.front(); q.pop();
        // cout << A.first << ' ' << A.second << ' ' << B.first << ' ' << B.second << ' ' << cnt << '\n';
        rep(ad, 0, 9) rep(bd, 0, 9){
            pii nA = {A.first + dx[ad], A.second + dy[ad]};
            pii nB = {B.first + dx[bd], B.second + dy[bd]};
            if(nA.first < 0 || nA.first >= N || nA.second < 0 || nA.second >= M) continue;
            if(nB.first < 0 || nB.first >= N || nB.second < 0 || nB.second >= M) continue;
            if(board[nA.first][nA.secoqnd] == 'X') continue;
            if(board[nB.first][nB.second] == 'X') continue;
            if(nA == nB) continue;
            if(nA == B && nB == A) continue;
            if(visited.count({nA, nB})) continue;
            if(nA == Bpos && nB == Apos){
                cout << cnt + 1;
                return;
            }
            visited.insert({nA, nB});
            q.push({nA, nB, cnt + 1});
        }
    }
    cout << -1;
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