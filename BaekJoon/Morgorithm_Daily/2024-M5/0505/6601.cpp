#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int dist[8][8];
map<char, int> mp = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void solve(){
    string A, B;
    while(1){
        cin >> A >> B;
        if(cin.eof()) break;
        rep(i, 0, 8) fill(dist[i], dist[i]+8, 1000);
        pii start = {mp[A[0]], A[1]-'1'}, end = {mp[B[0]], B[1]-'1'};
        queue<pii> q;
        q.push(start);
        dist[start.first][start.second] = 0;
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            rep(i, 0, 8){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx<0 || nx>=8 || ny<0 || ny>=8) continue;
                if(dist[nx][ny] > dist[x][y]+1){
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
        cout << "To get from " << A << " to " << B << " takes " << dist[end.first][end.second] << " knight moves.\n";
    }
    return;
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