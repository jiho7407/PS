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
int A[1000], DP[1000];

void solve(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    int ans = 0;
    for(int i = 0; i<N; i++){
        DP[i] = 1; // 자기자신
        for(int j = 0; j<i; j++){
            if(A[j] < A[i]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        ans = max(ans, DP[i]);
    }
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