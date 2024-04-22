#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

long long W, H, K, T;
const int mod = 998244353;

int main(){
    fastio();
    cin >> W >> H >> K >> T;
    long long ans = 1;
    for(int i = 0; i<K; i++){
        long long x, y;
        cin >> x >> y;
        ans *= (min(W, x+T) - max(1LL, x-T) + 1LL) * (min(H, y+T) - max(1LL, y-T) + 1LL) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}