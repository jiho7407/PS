#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M;
ll lst[1010];
ll dp[1010][1010];

ll td(ll left, ll right){
    if(left+1 == right) return 0;
    if(dp[left][right] != -1) return dp[left][right];
    dp[left][right] = 1e18;
    for(int i = left+1; i<right; i++){
        dp[left][right] = min(dp[left][right], td(left, i) + td(i, right) + lst[right] - lst[left]);
    }
    return dp[left][right];
}

void solve(){
    cin >> N >> M;
    for(int i = 1; i<=M; i++) cin >> lst[i];
    sort(lst+1, lst+M+1);
    lst[0] = 0; lst[M+1] = N;
    for(int i = 0; i<M+2; i++) fill(dp[i], dp[i]+M+2, -1);
    cout << td(0, M+1) << '\n';
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