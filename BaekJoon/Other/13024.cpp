#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll mx = 100010, mod = 1'000'000'007;
int N;
vector<int> links[mx];
ll DP[mx];
ll ans = 0;

ll mi(ll a, int p){
    if(p == 0) return 1;
    if(p == 1) return a;
    ll half = mi(a, p/2) % mod;
    ll result = (half*half)%mod;
    if(p%2) result = (result*a)%mod;
    return result;
}

ll dfs(int a, int par){
    for(auto g: links[a]){
        if(g == par) continue;
        DP[a] *= (dfs(g, a)+1);
        DP[a] %= mod;
    }
    return DP[a];
}

void dfs2(int a, int par, int fromp){
    ll temp = 1;
    for(auto g: links[a]){
        if(g==par) continue;
        temp *= DP[g]+1;
        temp %= mod;
    }
    ans = (ans + temp * (fromp+1)) % mod;

    for(auto g: links[a]){
        if(g == par) continue;
        dfs2(g, a, ((fromp+1)*temp%mod)*mi(DP[g]+1, mod-2)%mod);
    }
}

int main(){
    fastio();
    cin >> N;
    for(int i = 0; i<N-1; i++){
        int s, e;
        cin >> s >> e;
        links[s-1].push_back(e-1);
        links[e-1].push_back(s-1);
    }
    fill(DP, DP+N, 1);
    dfs(0, -1);
    dfs2(0, -1, 0);
    
    cout << ans << "\n";
    return 0;
}