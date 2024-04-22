#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
const int mod = 15746;

int main(void){
    
    fill(dp, dp+1000001, 0);
    int N;
    cin >> N;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=N; i++){
        dp[i] = (dp[i-2] + dp[i-1])%mod;
    }
    cout << dp[N];
}