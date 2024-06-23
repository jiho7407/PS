/*###############################################################################################################
##                                    Author : Kim Tae Yoon (Serendipity__)                                    ##
###############################################################################################################*/

#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define prntyes cout<<"Yes\n";
#define prntno cout<<"No\n";
using namespace std;
#ifndef ONLINE_JUDGE
#include "___debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // random int64 generator
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef __int128 ll128;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pii;
typedef complex<double> inum;
// Macros from KACTL pdf
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<double> vd;
const double PI = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LLINF = 1000000000000000000LL;
const ll MAX = 200005; // depending on the problem
const ll MOD = 998244353; // depending on the problem

struct DSU {
    int N;
    vector<int> parent, member;
    DSU() { N = 0; }
    DSU(int n) {
        N = n;
        parent.resize(n);
        member.resize(n);
        for (int i = 0; i < n; i++) { parent[i] = -1; member[i] = 1; }
    }
    int root(int n) {
        if (parent[n] == -1) { return n; }
        return parent[n] = root(parent[n]);
    }
    void merge(int r1, int r2) {
        r1 = root(r1);
        r2 = root(r2);
        if (r1 == r2) { return; }
        if (member[r1] < member[r2]) { swap(r1, r2); }
        parent[r2] = r1;
        member[r1] += member[r2];
    }
};

void solve() {
    ll N; cin>>N;
    vector<ll> f(N);
    vector<int> deg(N);
    for (int i=0;i<N;i++){
        cin>>f[i]; --f[i];
        deg[f[i]]++;
    }

    vector<bool> vis(N);
    vector<int> order;
    queue<int> que;
    for (int i=0;i<N;i++){
        if (deg[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int u = que.front(); que.pop();
        order.push_back(u);
        vis[u] = 1;
        deg[f[u]]--;
        if (deg[f[u]]==0){
            que.push(f[u]);
        }
    }

    DSU dsu = DSU(N);
    for (int i=0;i<N;i++){
        if (!vis[i]){
            dsu.merge(i,f[i]);
        }
    }
    vector<ll> dp(N);
    ll ans = 0;
    for (int i=0;i<N;i++){
        if (!vis[i]){
            dp[i] = dsu.member[dsu.root(i)];
            ans += dp[i];
        }
    }
    reverse(order.begin(), order.end());
    for (int& u:order){
        dp[u] = dp[f[u]]+1;
        ans += dp[u];
    }
    cout<<ans;

}

int main() {
    fastio;
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
