#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int dp[1000001];

void solve(){
    dp[0] = 1;
    for(int i = 1; i<=1000000; i++){
        dp[i] = dp[int(double(i)-sqrt(double(i)))] + dp[int(log(double(i)))] + dp[int(double(i)*sin(double(i))*sin(double(i)))];
        dp[i] %= 1000000;
    }
    while(1){
        int n;
        cin >> n;
        if(n == -1) break;
        cout << dp[n] << '\n';
    }
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