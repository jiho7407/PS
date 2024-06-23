#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

short N, M;
short A[2000][2000];

void solve(){
    cin >> N >> M;
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            int cnt = 0;
            for(int k = 0; k < M; k++){
                if(A[i][k] == A[j][k]) cnt++;
            }
            if(cnt%2) ans++;
        }
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}