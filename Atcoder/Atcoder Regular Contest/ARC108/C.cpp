#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
vector<pii> links[100001];
int ans[100001];

void solve(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        links[u].push_back({v, c});
        links[v].push_back({u, c});
    }
    ans[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto [v, c] : links[u]){
            if(ans[v] != 0) continue;
            if(ans[u] == c) ans[v] = (c+1)%N;
            else ans[v] = c;
            q.push(v);
        }
    }
    for(int i = 0; i < N; i++) cout << ans[i] << '\n';
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