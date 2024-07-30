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

int N, M;
int C[1000];
int DP[1000][201][11];

int calc(int a, int b){
    if(a <= b) return 0;
    else return (a-b)*(a-b);
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> C[i];
    fill_n(&DP[0][0][0], 1000*201*11, 1e9);
    DP[0][0][0] = 0;
    rep(i, 0, N-1){
        rep(j, 0, M+1){
            rep(k, 0, 11){
                if(DP[i][j][k] == 1e9) continue;
                rep(l, 0, 11){
                    if(j+l > M) break;
                    DP[i+1][j+l][l] = min(DP[i+1][j+l][l], DP[i][j][k] + calc(C[i]+k, C[i+1]+l));
                }
            }
        }
    }
    int ans = 1e9;
    rep(i, 0, M+1) rep(j, 0, M+1) ans = min(ans, DP[N-1][i][j]);
    cout << ans;
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