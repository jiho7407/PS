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

int N;
int A[2000];
int DP[2000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    fill(DP, DP+N, 1);
    rep(j, 1, N){
        rep(i, 0, j){
            if(A[i] > A[j]){
                DP[j] = max(DP[j], DP[i]+1);
            }
        }
    }
    int mx = 0;
    rep(i, 0, N) mx = max(mx, DP[i]);
    cout << N - mx;
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