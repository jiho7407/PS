#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, K;
int S[10010], D[10010];
int temp[10010];

int main(){
    fastio();
    cin >> N >> K;
    for(int i = 1; i<=N; i++) cin >> S[i];
    for(int i = 1; i<=N; i++) cin >> D[i];
    for(int i = 1; i<=K; i++){
        for(int j = 1; j<=N; j++){
            temp[D[j]] = S[j];
        }
        copy(temp, temp+N+1, S);
    }
    for(int i = 1; i<=N; i++) cout << S[i] << " ";
    return 0;
}