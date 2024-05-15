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
int DP[45][2];

void calc(){
    DP[0][0] = 1;
    DP[0][1] = 0;
    rep(i, 1, 45){
        DP[i][0] = DP[i-1][0] + DP[i-1][1];
        DP[i][1] = DP[i-1][0];
    }
    return;
}

void solve(){
    int N; cin >> N;
    cout << DP[N][0] + DP[N][1] << '\n';
    return;
}

int main(){
    fastio();
    calc();
    int tc = 1;
    cin >> tc;
    rep(i, 1, tc+1){
        cout << "Scenario #" << i << ":\n";
        solve();
        cout << '\n';
    }
    return 0;
}