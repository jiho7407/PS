#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int INF = 1234567890;
int N, K, C;
int DP[101][10001];
vector<int> coins;

int main(){
    fastio();
    cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> C;
        if(C<=K) coins.push_back(C);
    }
    for(int i = 0; i<=N; i++){
        fill(DP[i], DP[i]+K+1, INF);
        DP[i][0] = 0;
    }

    sort(coins.begin(), coins.end());
    for(int i = 1; i<=coins.size(); i++){
        int coin = coins[i-1];
        for(int j = 1; j<=K; j++){
            DP[i][j] = DP[i-1][j];
            if(j<coin) continue;
            DP[i][j] = min(DP[i][j], 1 + DP[i][j-coin]);
        }
    }
    // for(int i = 0; i<=coins.size(); i++){
    //     for(int j = 0; j<=K; j++){
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    int ans = DP[coins.size()][K];
    
    if(ans == INF) cout << -1;
    else cout << ans;
    return 0;
}