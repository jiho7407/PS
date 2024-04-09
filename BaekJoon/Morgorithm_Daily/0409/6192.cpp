#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int board[100][100];
int DP[100][100];

void solve(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        fill(DP[i], DP[i]+M, -1);
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    DP[0][0] = board[0][0];
    for(int j = 0; j<M-1; j++){
        for(int i = 0; i<N; i++){
            if(DP[i][j] == -1) continue;
            if(i+1 < N){
                DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j] + board[i+1][j+1]);
            }
            if(i-1 >= 0) {
                DP[i-1][j+1] = max(DP[i-1][j+1], DP[i][j] + board[i-1][j+1]);
            }
            DP[i][j+1] = max(DP[i][j+1], DP[i][j] + board[i][j+1]);
        }
    }
    cout << DP[N-1][M-1] << '\n';
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