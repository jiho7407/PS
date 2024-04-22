#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N;
ll board[100100];
ll DP[100100];

void solve(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> board[i];
    }
    fill(DP, DP+100100, 0);
    DP[1] = board[1];
    DP[2] = max(board[1] + board[2]/2, board[2]);
    DP[3] = max(board[1]+board[3], board[2]+board[3]/2);
    for(int i=4; i<=N; i++){
        DP[i] = max(max(DP[i-3], DP[i-2])+board[i], max(DP[i-4], DP[i-3])+board[i-1]+board[i]/2);
    }
    cout << max(DP[N-1], DP[N]) << "\n";
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}