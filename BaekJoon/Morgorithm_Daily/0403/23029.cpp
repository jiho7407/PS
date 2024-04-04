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
ll DP[100100][3];

void solve(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> board[i];
    }
    for(int i=0; i<=N; i++){
        for(int j=0; j<3; j++){
            DP[i][j] = 0;
        }
    }
    DP[1][1] = board[1];
    for(int i=2; i<=N; i++){
        DP[i][0] = max(DP[i-1][0], max(DP[i-1][1], DP[i-1][2]));
        DP[i][1] = DP[i-1][0] + board[i];
        DP[i][2] = DP[i-1][1] + board[i]/2;
    }
    cout << max(DP[N][0], max(DP[N][1], DP[N][2])) << '\n';
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}