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

int N, M, X, Y;
vector<int> links[1000];
bool visited[1000];

void solve(){
    cin >> N >> M >> X >> Y;
    rep(i, 0, M){
        int a, b; cin >> a >> b; a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    queue<int> q;
    q.push(X-1);
    while(Y--){
        fill(visited, visited+N, false);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : links[cur]){
                if(visited[nxt]) continue;
                visited[nxt] = true;
            }
        }
        rep(i, 0, N) if(visited[i]) q.push(i);
    }
    if(q.empty()) {cout << -1; return;}
    while(!q.empty()){
        cout << q.front()+1 << ' ';
        q.pop();
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