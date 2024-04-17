#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mod = 9901, mx = 1'000'001;
int N;
int pows[mx];
int dp[mx][5];

int hanoi(int N, int r){
    if(N==1) return 1;
    if(r==3) return pows[N]-1;
    if(dp[N][r]!=-1) return dp[N][r];
    int ret = 1e9;
    // for(int k = 1; k<N; k++){
    int k = N - round(sqrt(2*N+1)) + 1;
    ret = min(ret, (2*hanoi(k, r)+(pows[N-k]-1))%mod);
    // }
    return dp[N][r] = ret;
}

void solve(){
    cin >> N;
    fill(pows, pows+N, 1);
    for(int i = 1; i<N; i++) pows[i] = (pows[i-1]*2)%mod;
    for(int i = 0; i<=N; i++) fill(dp[i], dp[i]+5, -1);
    cout << hanoi(N, 4) << "\n";
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