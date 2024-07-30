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

int DP[51][1010];

void solve(){
    int N, S;
    cin >> N >> S;
    DP[2][0] = 1;
    rep(i, 0, N){
        rep(j, 0, S+1){
            if(DP[i][j] == 0) continue;
            for(int k = 1; j + k*(k+1)/2 <= S; k++){
                if(i+k > N) break;
                DP[i+k][j + k*(k+1)/2] = 1;
            }
        }
    }
    // rep(i, 0, N+1){
    //     rep(j, 0, S+1) cout << DP[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << DP[N][S] << '\n';
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