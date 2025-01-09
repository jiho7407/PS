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

void solve(){
    int N, M; cin >> N >> M;
    vector<vector<int>> links(N);
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    vector<int> dist(N, -1);
    queue<int> Q;
    Q.push(0);
    dist[0] = 0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto nxt:links[cur]){
            if(dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1;
                Q.push(nxt);
            }
        }
    }
    int mx = -1, idx = -1, cnt = 0;
    rep(i, 0, N){
        if(dist[i] > mx){
            mx = dist[i];
            idx = i;
            cnt = 1;
        }
        else if(dist[i] == mx) cnt++;
    }
    cout << idx+1 << ' ' << mx << ' ' << cnt;
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