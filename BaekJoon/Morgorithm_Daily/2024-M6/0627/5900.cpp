#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, K;
ll DP[11][1'000'001];

ll TopDown(ll N, ll K){
    // cout << N << ' ' << K << endl;
    if(DP[K][N] != -1) return DP[K][N];
    if(N == K) return DP[K][N] = 1;
    if(K == 0) return DP[K][N] = 1;
    if(N < K) return 0;

    return DP[K][N] = TopDown(N-1, K-1) + TopDown(N-1, K);
}

void solve(){
    cin >> N >> K;
    if(N == 1){
        rep(i, 0, K) cout << 1;
        return;
    }
    ll M = K, cnt = 1;
    while(1){
        ll ret = cnt * (M+1) / (M-K+1);
        if(ret >= N) break;
        cnt = ret; M++;
    }
    fill_n(&DP[0][0], 11*1'000'001, -1);
    cout << 1;

    K--;
    ll left = N - cnt;
    for(ll i = M; i >= 1; i--){
        ll ret = TopDown(i-1, K); // 0 선택
        if(left > ret){
            cout << 1;
            left -= ret;
            K--;
        }else cout << 0;
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}