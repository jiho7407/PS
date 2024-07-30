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
int A[5000], pfsum[5001];
int DP[5000][5000], OPT[5000][5000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    pfsum[0] = 0;
    rep(i, 1, N+1) pfsum[i] = pfsum[i-1] + A[i-1];
    fill_n(&DP[0][0], 5000*5000, 1e9);
    fill_n(&OPT[0][0], 5000*5000, 0);
    rep(i, 0, N) DP[i][i] = 0, OPT[i][i] = i;
    rep(k, 1, N){ // k = j - i
        rep(i, 0, N-k){
            int j = i + k;
            rep(l, OPT[i][j-1], OPT[i+1][j]+1){
                int tmp = DP[i][l] + DP[l+1][j] + pfsum[j+1] - pfsum[i];
                if(tmp < DP[i][j]){
                    DP[i][j] = tmp;
                    OPT[i][j] = l;
                }
            }
        }
    }
    cout << DP[0][N-1] << '\n';
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