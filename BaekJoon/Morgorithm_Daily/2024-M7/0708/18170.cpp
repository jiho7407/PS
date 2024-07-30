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
string board[20];
pii coin1, coin2;
set<pair<pii, pii>> visited;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    coin1 = coin2 = {-1, -1};
    rep(i, 0, N) rep(j, 0, M){
        if(board[i][j] == 'o'){
            if(coin1 == pii(-1, -1)) coin1 = {i, j};
            else coin2 = {i, j};
        }
    }
    queue<tuple<pii, pii, int>> q;
    q.push({coin1, coin2, 0});
    visited.insert({coin1, coin2});
    while(!q.empty()){
        auto [c1, c2, cnt] = q.front(); q.pop();
        auto [cx1, cy1] = c1;
        auto [cx2, cy2] = c2;
        rep(d, 0, 4){
            int nx1 = cx1 + dx[d], ny1 = cy1 + dy[d];
            int nx2 = cx2 + dx[d], ny2 = cy2 + dy[d];
            bool out1 = nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M;
            bool out2 = nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= M;
            if(out1 && out2) continue;
            if(out1 || out2){
                cout << cnt+1 << '\n';
                return;
            }
            if(board[nx1][ny1] == '#') nx1 = cx1, ny1 = cy1;
            if(board[nx2][ny2] == '#') nx2 = cx2, ny2 = cy2;
            if(visited.count({{nx1, ny1}, {nx2, ny2}})) continue;
            visited.insert({{nx1, ny1}, {nx2, ny2}});
            q.push({{nx1, ny1}, {nx2, ny2}, cnt+1});
        }
    }
    cout << -1 << '\n';
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