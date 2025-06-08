#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l; i<r; i++)
using namespace std;
using ll = long long;

int N, M, K;
string S[500];

int main(){
    ll ans = 0;
    cin >> N >> M >> K;
    rep(i, 0, N) cin >> S[i];
    rep(a, 0, K) rep(b, 0, K){
        map<char, ll> mp;
        rep(i, 0, N/K) rep(j, 0, M/K){
            mp[S[i*K+a][j*K+b]]++;
        }
        char mc = 'A';
        ll mx = -1;
        for(auto [k, v]: mp) if(v > mx){
            mc = k;
            mx = v;
        }
        rep(i, 0, N/K) rep(j, 0, M/K){
            S[i*K+a][j*K+b] = mc;
        }
        ans += (N/K)*(M/K) - mx;
    }
    cout << ans << '\n';
    rep(i, 0, N) cout << S[i] << '\n';

    return 0;
}