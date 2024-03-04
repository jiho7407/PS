#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int DP[1010][1010];
string S;

int main(){
    fastio();
    cin >> S;
    int N = S.length();
    for(int i = 0; i<N; i++) fill(DP[i], DP[i]+N, 0);
    for(int i = 0; i<N; i++) DP[i][i] = 1;
    for(int i = 1; i<N; i++){
        for(int j = 0; j<N-i; j++){
            DP[j][j+i] = DP[j+1][j+i] + DP[j][j+i-1] - DP[j+1][j+i-1];
            if(S[j] == S[j+i]) DP[j][j+i] += DP[j+1][j+i-1] + 1;
            DP[j][j+i] %= 10007;
            if(DP[j][j+i]<0) DP[j][j+i] += 10007;
        }
    }
    cout << DP[0][N-1];
    return 0;
}