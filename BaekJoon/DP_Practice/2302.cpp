#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int DP[41];

void calc(){
    fill(DP, DP+41, 0);
    DP[0] = 1;
    DP[1] = 1;
    for(int i = 2; i<=40; i++){
        DP[i] = DP[i-2] + DP[i-1];
    }
    return;
}

int main(){
    fastio();
    calc();
    cin >> N >> M;
    int last, cur;
    int ans = 1;
    last = 0;
    for(int i = 0; i<M; i++){
        cin >> cur;
        ans *= DP[cur-last-1];
        last = cur;
    }
    ans *= DP[N-last];
    cout << ans;
    return 0;
}