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

ll calc(int cur, int stat){
    if(DP[cur][stat] != -1) return DP[cur][stat];
    ll temp = 0;
    if(stat == 0){
        temp = max(calc(cur-1, 0), max(calc(cur-1, 1), calc(cur-1, 2)));
    }else if(stat == 1){
        temp = calc(cur-1, 0) + board[cur];
    }else{
        temp = calc(cur-1, 1) + board[cur]/2;
    }
    return DP[cur][stat] = temp;
}

void solve(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> board[i];
    }
    for(int i=0; i<=N; i++){
        for(int j=0; j<3; j++){
            DP[i][j] = -1;
        }
    }
    DP[0][0] = 0;
    DP[1][0] = 0;
    DP[1][1] = board[1];
    DP[1][2] = -10000000;
    ll ans = 0;
    for(int i = 0; i<3; i++){
        ans = max(ans, calc(N, i));
    }
    cout << ans << "\n";
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}