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

int N, H, D, K;
int DP[3][25][70];
int R[18];

void solve(){
    cin >> N >> H >> D >> K;
    rep(i, 0, N) cin >> R[i];
    rep(i, 0, 2){rep(j, 0, N+1) fill(DP[i][j], DP[i][j]+70, -1);};

    DP[0][0][D] = H;
    int ans = 0;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<70; k++){
                if(DP[i][j][k] == -1) continue;
                // 웅크리기
                DP[i][j+1][k] = max(DP[i][j+1][k], DP[i][j][k] - max(0, (R[j] - k)/2));

                //네발로 걷기
                DP[i][j+1][k+K] = max(DP[i][j+1][k+K], DP[i][j][k] - max(0, R[j] - (k+K)));

                //깜짝 놀라게 하기 -> 다음턴에 안맞으니까 웅크리기 의미 X. 네발로 걷기 사용
                if(i == 1) continue;
                DP[i+1][j+2][k+K] = max(DP[i+1][j+2][k+K], DP[i][j][k] - max(0, R[j] - k));
            }
        }
    }
    rep(i, 0, 2){rep(k, 0, 70) ans = max(ans, DP[i][N][k]);};
    if(ans == 0) cout << -1;
    else cout << ans;
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