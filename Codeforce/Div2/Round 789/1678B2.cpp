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

int N;
string S;
pii DP[200001][2];

void solve(){
    cin >> N >> S;

    DP[0][0] = DP[0][1] = {0, 1};
    for(int i = 0; i<N; i+=2){
        DP[i+2][0] = DP[i+2][1] = {1e9, 1e9};
        if(S[i] == S[i+1]){
            if(S[i] == '0'){
                DP[i+2][0] = min(
                    DP[i][0],
                    (pii){DP[i][1].first, DP[i][1].second + 1}
                    );
                DP[i+2][1] = min(
                    (pii){DP[i][0].first + 2, DP[i][0].second + 1},
                    (pii){DP[i][1].first + 2, DP[i][1].second}
                    );
            }
            else{
                DP[i+2][0] = min(
                    (pii){DP[i][0].first + 2, DP[i][0].second},
                    (pii){DP[i][1].first + 2, DP[i][1].second + 1}
                    );
                DP[i+2][1] = min(
                    DP[i][1],
                    (pii){DP[i][0].first, DP[i][0].second + 1}
                    );
            }
        }
        else{
            DP[i+2][0] = min(
                (pii){DP[i][0].first + 1, DP[i][0].second},
                (pii){DP[i][1].first + 1, DP[i][1].second + 1}
                );
            DP[i+2][1] = min(
                (pii){DP[i][1].first + 1, DP[i][1].second},
                (pii){DP[i][0].first + 1, DP[i][0].second + 1}
                );
        }
    }
    
    pii ans = min(DP[N][0], DP[N][1]);
    cout << ans.first << ' ' << ans.second << '\n';
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