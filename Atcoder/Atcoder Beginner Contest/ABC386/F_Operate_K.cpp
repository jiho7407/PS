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

int K;
string S, T;
int N, M;

void solve(){
    cin >> K;
    cin >> S >> T;
    N = S.size(); M = T.size();
    if(abs(M-N) > K){
        cout << "No";
        return;
    }

    vector<vector<int>> DP(N+1, vector<int>(2*K+1, 1e9));
    DP[0][K] = 0;
    rep(i, 0, N+1){
        rep(dj, 0, 2*K+1){
            int j = i + dj - K;
            if(j<0) continue;
            if(j>M) break;

            if(i>0 && dj<2*K) DP[i][dj] = min(DP[i][dj], DP[i-1][dj+1]+1);
            if(j>0 && dj>0) DP[i][dj] = min(DP[i][dj], DP[i][dj-1]+1);
            if(i>0 && j>0){
                if(S[i-1] == T[j-1]) DP[i][dj] = min(DP[i][dj], DP[i-1][dj]);
                else DP[i][dj] = min(DP[i][dj], DP[i-1][dj]+1);
            }
        }
    }

    if(DP[N][K+M-N] <= K) cout << "Yes";
    else cout << "No";
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