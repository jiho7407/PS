#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, K;
int lst[200];

int main(){
    fastio();
    cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> lst[i];
    }
    bool ans = false;
    int cur = 0;
    for(int i = 0; i<N; i++){
        if(cur == K){
            cout << i;
            ans = true;
            break;
        }
        cur = lst[cur];
    }
    if(!ans) cout << -1;
    return 0;
}