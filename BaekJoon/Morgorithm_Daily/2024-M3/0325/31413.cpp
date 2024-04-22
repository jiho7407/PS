#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M, A, D;
int score[1010];
int DP[1010][1010]; //헌혈횟수, 현재 날짜 최대 가산점

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<N; i++) cin >> score[i];
    cin >> A >> D;
    for(int i = 0; i<N; i++){
        fill(DP[i], DP[i]+N, -1);
        DP[i][0] = 0;
    }
    for(int i = 1; i<=N; i++) DP[0][i] = DP[0][i-1]+score[i-1];
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            DP[i][j] = DP[i][j-1]+score[j-1];
            if(j>=D) DP[i][j] = max(DP[i][j], DP[i-1][j-D]+A);
        }
        DP[i][N] = max(DP[i][N], DP[i-1][N-1]+A);
    }
    int ans = -1;
    for(int i = 0; i<=N; i++){
        int mx = 0;
        for(int j = 0; j<=N; j++) mx = max(mx, DP[i][j]);
        if(mx>=M){
            ans = i;
            break;
        }
    }
    // for(int i = 0; i<=N; i++){
    //     for(int j = 0; j<=N; j++) cout << DP[i][j] << " ";
    //     cout << "\n";
    // }
    cout << ans;
    return 0;
}