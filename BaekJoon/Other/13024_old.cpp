#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const long long mx = 100010, mod = 1'000'000'007;
int N;
vector<int> links[mx];
long long DP[mx][3];

long long mi(long long a, int p){
    if(p == 0) return 1;
    if(p == 1) return a;
    long long half = mi(a, p/2) % mod;
    long long result = half*half%mod;
    if(p%2) result = result*a%mod;
    
    return result;
}

void dfs(int a, int par){
    long long cnts = 1, childsum = 0, childcnt = 0;
    for(auto b: links[a]){
        if(b == par) continue;
        dfs(b, a);
        DP[a][1] += DP[b][1];
        childsum += DP[b][0];
        cnts *= (DP[b][2]+1);
        childcnt++;
    }

    DP[a][1] += childsum;
    DP[a][2] += cnts;
    DP[a][0] += cnts;

    for(auto b: links[a]){
        if(b == par) continue;
        long long temp = DP[b][0] * cnts % mod;
        temp *= mi(DP[b][2]+1, mod-2) % mod;
        DP[a][0] += temp % mod;
        DP[a][0] %= mod;

        // cout << a << " " << b << " " << DP[b][2] << " " << mi(DP[b][2]+1, mod-2) << "/" << cnts << " " << temp%mod << "\n";
    }

    DP[a][0] %= mod;
    DP[a][1] %= mod;
    DP[a][2] %= mod;

    return;
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
    for(int i = 0; i<N; i++){
        fill(DP[i], DP[i]+3, 0);
    }
    dfs(0, -1);
    cout << (DP[0][0] + DP[0][1]) % mod << "\n";

    // for(int i = 0; i<N; i++){
    //     cout << DP[i][0] << " " << DP[i][1] << " " << DP[i][2] << "\n";
    // }
    return 0;
}