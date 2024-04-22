#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 100100;
int N;
int A[mxN];

bool cmp(int a, int b){
    return a > b;
}

void solve(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A+N, cmp);
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(A[i] - i <= 0) break;
        ans += A[i] - i;
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}