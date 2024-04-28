#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int INF = 1e9;
int N, K;
int C[20][20];
int DP[1<<20];

void solve(){
    cin >> N >> K;
    rep(i, 0, N) rep(j, 0, N) cin >> C[i][j];
    fill(DP, DP + (1 << N), INF);
    DP[0] = 0;
    rep(i, 0, N){
        rep(j, 0, 1 << N){
            if(__builtin_popcount(j) != i) continue;
            if(DP[j] == INF) continue;
            rep(k, 0, N){
                if(j & (1 << k)) continue;
                rep(l, 0, N){
                    if(k == l) continue;
                    if(j & (1<<l)) continue;
                    DP[j | (1 << k)] = min(DP[j | (1 << k)], DP[j] + C[k][l]);
                }
            }
        }
    }
    int ans = 1e9;
    rep(i, 0, 1 << N){
        if(__builtin_popcount(i) == N-K){
            ans = min(ans, DP[i]);
        }
    }
    cout << ans << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}