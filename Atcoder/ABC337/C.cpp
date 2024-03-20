#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, S, nxt[300010];

int main(){
    fastio();
    cin >> N;
    fill(nxt, nxt+N+1, -1);
    for(int i = 1; i<=N; i++){
        int cmd;
        cin >> cmd;
        if(cmd == -1){
            S = i;
            continue;
        }
        nxt[cmd] = i;
    }
    for(int i = S; i != -1; i = nxt[i]){
        cout << i << " ";
    }
    return 0;
}