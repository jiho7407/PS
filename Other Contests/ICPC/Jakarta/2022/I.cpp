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

int N;
vector<int> links[100001];
int par[100001], depth[100001];
vector<pii> query, ans;

vector<int> childs[100001];

void dfs(int cur, int p, int d){
    par[cur] = p;
    depth[cur] = d;
    // childs[cur].clear();
    for(int nxt : links[cur]){
        if(nxt == p) continue;
        dfs(nxt, cur, d+1);
        // childs[cur].push_back(nxt);
    }
}

void calc(int root){
    int idx = 0;
    dfs(root, -1, 0);
    int C = links[root].back();
    int conn = -1;
    ans.clear();
    
    for(auto [u, v]: query){
        if(depth[u] > depth[v]) swap(u, v);
        if(u == root){
            if(idx+1 >= links[root].size()){
                ans.push_back({v, conn});
            }
            else{
                ans.push_back({v, links[root][idx+1]});
                idx++;
            }
        }
        else{
            ans.push_back({root, v});
            if(par[v] != C) conn = v;
        }
    }
}

void solve(){
    // 트리 입력받기
    cin >> N;
    rep(i, 0, N-1){
        int u, v; cin >> u >> v;
        links[u].push_back(v);
        links[v].push_back(u);
        query.push_back({u, v});
    }

    // star graph이면 불가능
    rep(i, 1, N+1){
        if(links[i].size() == N-1){
            cout << -1 << '\n';
            return;
        }
    }

    int root;
    if(links[query.back().first].size() > 1) root = query.back().first;
    else root = query.back().second;

    calc(root);
    if(ans.size() == N-1){
        for(auto [u, v]: ans) cout << u << ' ' << v << '\n';
        return;
    }
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