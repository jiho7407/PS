#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N;
ll board[100][100], DP[100][100];

int main(){
    fastio();
    cin >> N;
    for(ll i = 0; i<N; i++){
        fill(DP[i], DP[i]+N, 0);
        for(ll j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    DP[0][0] = 1;
    for(ll i = 0; i<N; i++){
        for(ll j = 0; j<N; j++){
            if(i==N-1 && j==N-1) break;
            ll m = board[i][j];
            if(j+m < N) DP[i][j+m] += DP[i][j];
            if(i+m < N) DP[i+m][j] += DP[i][j];
        }
    }
    cout << DP[N-1][N-1];
    return 0;
}