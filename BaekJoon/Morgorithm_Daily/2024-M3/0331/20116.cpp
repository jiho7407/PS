#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, L;
ll X[200000];


int main(){
    fastio();
    cin >> N >> L;
    for(int i = 0; i<N; i++) cin >> X[i];
    ll cursum = X[N-1], cnt = 1;
    bool stable = true;
    for(int i = N-2; i>=0; i--){
        if(cursum <= (X[i] - L) * cnt) stable = false;
        if((X[i] + L) * cnt <= cursum) stable = false;
        cursum += X[i]; cnt++;
    }
    if(stable) cout << "stable";
    else cout << "unstable";
    return 0;
}