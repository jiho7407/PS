#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

short N, M;
short A[2000][2000];

void solve(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    vector<bitset<2000>> ansbit(N);
    vector<bitset<2000>> curbit(1000);
    for(int j = 0; j<M; j++){
        for(int i = 0; i<N; i++) curbit[A[i][j]].set(i);
        for(int i = 0; i<N; i++){
            ansbit[i] ^= curbit[A[i][j]];
            ansbit[i][i].flip();
        }
        for(int i = 0; i<N; i++) curbit[A[i][j]].reset(i);
    }
    int ans = 0;
    for(int i = 0; i<N; i++){
        ans += ansbit[i].count();
    }
    cout << ans/2;
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