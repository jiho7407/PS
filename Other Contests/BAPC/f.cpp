#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mxN = 100010, INF = 1234567890;
ll N, C;
ll A[mxN], H[mxN];

void solve(){
    cin >> N >> C;
    for(int i = 0; i<N; i++) cin >> A[i];
    fill(H, H+N, 0);
    H[0] = A[0];
    for(int i = 1; i<N; i++){
        H[i] = max(0LL, H[i-1] - C) + A[i];
    }
    ll ans = -1;
    ll mntime = INF;
    for(int i = 0; i<N; i++){
        ll time = H[i]/C;
        if(i + time >= N) continue;
        if(time < mntime){
            mntime = time;
            ans = i;
        }
    }
    if(ans == -1) cout << "impossible";
    else cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}