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

int N;
int links[200001][2];
int deg[200001];

int dfs(int cur){
    if(links[cur][0]+links[cur][1] == -2) return deg[cur]=1;
    rep(nxt, 0, 2){
        if(links[cur][nxt] != -1) deg[cur] += dfs(links[cur][nxt]);
    }
    return deg[cur];
}

int dfs2(int cur, int K){
    if(links[cur][0]+links[cur][1] == -2) return cur;
    if(links[cur][0] == -1) return dfs2(links[cur][1], K);
    if(links[cur][1] == -1) return dfs2(links[cur][0], K);
    if(K%2) return dfs2(links[cur][0], (K+1)/2);
    else return dfs2(links[cur][1], K/2);
}

void solve(){
    cin >> N;
    rep(i, 1, N+1){
        cin >> links[i][0] >> links[i][1];
    }
    fill(deg, deg+N+1, 0);
    dfs(1);
    ll K; cin >> K;
    cout << dfs2(1, K) << '\n';
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