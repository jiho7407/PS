#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int K, N;
ll coins[16], costs[100001], pfsum[100001];
ll dp[17][1<<16];

void solve(){
    cin >> K >> N;
    for(int i = 0; i < K; i++) cin >> coins[i];
    for(int i = 1; i <= N; i++){
        cin >> costs[i];
        pfsum[i] = pfsum[i-1] + costs[i];
    }
    for(int i = 0; i <= K; i++) fill(dp[i], dp[i] + (1<<K), -1);
    dp[0][0] = 0;
    ll ans = -1;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j < (1<<K); j++){
            if(dp[i][j] == -1) continue;
            if(dp[i][j] >= N){
                ll temp = 0;
                for(int k = 0; k<K; k++){
                    if(j & (1<<k)) continue;
                    temp += coins[k];
                }
                ans = max(ans, temp);
            }
            for(int k = 0; k<K; k++){
                if(j & (1<<k)) continue;
                ll ok = dp[i][j]+1, ng = N+1;
                while(ng-ok > 1){
                    ll mid = (ok+ng)/2;
                    if(pfsum[mid] - pfsum[dp[i][j]] <= coins[k]) ok = mid;
                    else ng = mid;
                }
                if(dp[i+1][j|(1<<k)] == -1 || dp[i+1][j|(1<<k)] < ok){
                    dp[i+1][j|(1<<k)] = ok;
                }
            }
        }
    }
    cout << ans;
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