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

int N;
vector<int> links[100000];
int depth[100000], parent[100000][20];
vector<int> order;

void dfs(int cur){
    for(auto nxt: links[cur]){
        depth[nxt] = depth[cur] + 1;
        parent[nxt][0] = cur;
        dfs(nxt);
    }
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        order.push_back(cur);
        for(auto nxt: links[cur]){
            q.push(nxt);
        }
    }
}

void makeLCA(){
    rep(j, 1, 20) rep(i, 0, N){
        parent[i][j] = parent[parent[i][j-1]][j-1];
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    rep(i, 0, 20) if(diff & (1<<i)) a = parent[a][i];
    if(a == b) return a;
    for(int i = 19; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
}

void solve(){
    cin >> N;
    rep(i, 1, N){
        int x; cin >> x; x--;
        links[x].push_back(i);
    }
    dfs(0); bfs(0);
    makeLCA();
    ll ans = 0;
    rep(i, 0, N-1) ans += dist(order[i], order[i+1]);
    cout << ans;
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