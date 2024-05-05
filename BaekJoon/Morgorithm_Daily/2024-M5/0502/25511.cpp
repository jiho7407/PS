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

int N, K;
vector<int> links[100000];
int A[100000];

void dfs(int cur, int par, int depth){
    if(A[cur] == K) cout << depth << '\n';
    for(auto nxt : links[cur]){
        if(nxt == par) continue;
        dfs(nxt, cur, depth+1);
    }
}

void solve(){
    cin >> N >> K;
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    rep(i, 0, N){
        cin >> A[i];
    }
    dfs(0, -1, 0);
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