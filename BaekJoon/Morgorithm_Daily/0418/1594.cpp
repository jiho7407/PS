#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
string S;
int dp[1001];
vector<int> ans = {0};

bool dfs(int idx, int score){
    if(idx > 0 && score < dp[idx-1]) return false;
    if(idx == N) return true;
    bool res = false;
    if(idx+2 <= N){
        ans.push_back(idx+2);
        if(S[idx] == S[idx+1]) res = res|dfs(idx+2, score+2);
        else res = res|dfs(idx+2, score);
        if(res) return true;
        ans.pop_back();
    }
    if(idx+3 <= N){
        ans.push_back(idx+3);
        if(S[idx] == S[idx+1] && S[idx] == S[idx+2]) res = res|dfs(idx+3, score+2);
        else if(S[idx] == S[idx+1] || S[idx] == S[idx+2] || S[idx+1] == S[idx+2]) res = res|dfs(idx+3, score+1);
        else res = res|dfs(idx+3, score);
        if(res) return true;
        ans.pop_back();
    }
    return false;
}

void solve(){
    cin >> S; N = S.size();
    fill(dp, dp+N, -1);
    (S[0] == S[1]) ? dp[1] = 2 : dp[1] = 0;
    if(S[0] == S[1] && S[1] == S[2]) dp[2] = 2;
    else if(S[0] == S[1] || S[1] == S[2] || S[0] == S[2]) dp[2] = 1;
    else dp[2] = 0;
    (S[2] == S[3]) ? dp[3] = dp[1] + 2 : dp[3] = dp[1];
    for(int i = 4; i < N; i++){
        dp[i] = max(dp[i-2], dp[i-3]);
        if(S[i] == S[i-1]) dp[i] = max(dp[i], dp[i-2] + 2);
        if(S[i] == S[i-1] && S[i] == S[i-2]) dp[i] = max(dp[i], dp[i-3] + 2);
        else if(S[i] == S[i-1] || S[i] == S[i-2] || S[i-1] == S[i-2]) dp[i] = max(dp[i], dp[i-3] + 1);
    }
    dfs(0, 0);
    for(int i = 0; i<ans.size()-1; i++){
        for(int j = ans[i]; j<ans[i+1]; j++) cout << S[j];
        if(i == ans.size()-2) cout << '\n';
        else cout << '-';
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

// void solve(){
//     cin >> S; N = S.size();
//     for(int i = 0; i<N; i++) fill(dp[i], dp[i]+2, 0);
//     (S[0] == S[1]) ? dp[1][0] = 2 : dp[1][0] = 0;
//     if (S[0] == S[1] && S[1] == S[2]) dp[2][1] = 2;
//     else if(S[0] == S[1] || S[1] == S[2] || S[0] == S[2]) dp[2][1] = 1;
//     else dp[2][1] = 0;
//     for(int i = 3; i < N; i++){
//         if(S[i] == S[i-1]) dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + 2;
//         else dp[i][0] = max(dp[i-2][0], dp[i-2][1]) ;

//         if(S[i] == S[i-1] && S[i] == S[i-2]) dp[i][1] = max(dp[i-3][0], dp[i-3][1]) + 2;
//         else if(S[i] == S[i-1] || S[i] == S[i-2] || S[i-1] == S[i-2]) dp[i][1] = max(dp[i-3][0], dp[i-3][1])  + 1;
//         else dp[i][1] = max(dp[i-3][0], dp[i-3][1]);
//     }
//     // dfs(0, 0);
//     // for(int i = 0; i<ans.size(); i++) cout << ans[i] << ' ';
//     // cout << '\n';
//     for(int i = 0; i < N; i++){
//         cout << dp[i][0] << ' ' << dp[i][1] << '\n';
//     }
//     return;
// }