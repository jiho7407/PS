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
int A[1000000];

void solve(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    vector<int> DP;
    DP.push_back(A[0]);
    for(int i = 1; i<N; i++){
        if(DP.back() < A[i]){
            DP.push_back(A[i]);
        }
        else{
            int idx = lower_bound(DP.begin(), DP.end(), A[i]) - DP.begin();
            DP[idx] = A[i];
        }
    }
    cout << DP.size() << "\n";
    for(auto x: DP) cout << x << " ";
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