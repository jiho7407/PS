#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int T, N;
int A[501];
bool DP[501][5001];
bool table[501];

void rec(int i, int j){
    if(i == 0) return;
    if(DP[i][j] == DP[i-1][j]){
        rec(i-1, j);
    }else{
        table[i] = true;
        rec(i-1, j-A[i]);
    }
}

void solve(){
    cin >> T >> N;
    fill(DP[0], DP[0] + T+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        fill(DP[i], DP[i] + T+1, 0);
    }
    for(int i = 1; i<=N; i++){
        DP[i][A[i]] = true;
        for(int j = A[i]+1; j<=T; j++){
            DP[i][j] = DP[i-1][j];
            if(DP[i-1][j-A[i]]) DP[i][j] = true;
        }
    }
    fill(table, table + N+1, false);
    rec(N, T);
    int timeA = 0, timeB = 0;
    for(int i = 1; i<=N; i++){
        if(table[i]){
            cout << timeA << " ";
            timeA += A[i];
        }else{
            cout << timeB << " ";
            timeB += A[i];
        }
    }
    // cout << "\n" << timeA << " " << timeB << "\n";
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}