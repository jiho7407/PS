#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
string S = "narek";
vector<string> v;
int DP[1001][5];

void solve(){
    cin >> N >> M;
    v.resize(N);
    rep(i, 0, N) cin >> v[i];
    rep(i, 0, N+1) rep(j, 0, 5) DP[i][j] = -1e9;
    DP[0][0] = 0;
    rep(i, 0, N){
        rep(j, 0, 5){
            int idx = j;
            int allcnt = 0, narekcnt = 0;
            rep(k, 0, M){
                char op = v[i][k];
                if(op == S[idx]){
                    if(idx == 4) narekcnt++;
                    idx = (idx+1)%5;
                }
                
                bool flag = false;
                rep(l, 0, 5) if(S[l] == op) flag = true;
                if(flag) allcnt++;
            }
            allcnt -= narekcnt*5;
            int addscore = narekcnt*5 - allcnt;
            DP[i+1][idx] = max(DP[i+1][idx], DP[i][j] + addscore);
            DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
        }
    }

    int ans = -1e9;
    rep(i, 0, 5) ans = max(ans, DP[N][i]);
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}