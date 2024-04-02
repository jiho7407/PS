#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, K;
int ice[1'000'100];

void solve(){
    cin >> N >> K;
    fill(ice, ice+1000100, 0);
    for(int i = 0; i<N; i++){
        int g, x;
        cin >> g >> x;
        ice[x] += g;
    }
    long long sum = 0;
    for(int i = 0; i<=min(2*K, 1'000'000); i++) sum += ice[i];
    if(K>=500000) {cout << sum; return;}
    long long ans = sum;
    for(int i = 2*K+1; i<=1000000; i++){
        sum += ice[i];
        sum -= ice[i-2*K-1];
        ans = max(ans, sum);
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}