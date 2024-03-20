#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, K, C;
int DP[10001];
vector<int> coins;

int main(){
    fastio();
    cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> C;
        if(C<=K) coins.push_back(C);
    }
    fill(DP, DP+K+1, 0);
    DP[0] = 1;

    sort(coins.begin(), coins.end());
    for(int i = 0; i<coins.size(); i++){
        int coin = coins[i];
        for(int j = 1; j<=K; j++){
            if(j<coin) continue;
            DP[j] += DP[j-coin];
        }
    }
    cout << DP[K];
    return 0;
}