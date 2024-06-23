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

int N, K, M;
vector<int> links[101000];
bool visited[101000];

void solve(){
    cin >> N >> K >> M;
    rep(i, 0, M){
        rep(j, 0, K){
            int x; cin >> x; x--;
            links[100000+i].push_back(x);
            links[x].push_back(100000+i);
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0}); visited[0] = true;
    while(!q.empty()){
        auto [cur, cnt] = q.front(); q.pop();
        if(cur == N-1){
            cout << cnt/2+1;
            return;
        }
        for(auto nxt :links[cur]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            q.push({nxt, cnt+1});
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