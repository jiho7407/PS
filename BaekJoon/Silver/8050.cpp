#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());
    int diff = N/2, cnt = 0;
    rep(i, 0, (N+1)/2) cnt += (A[i] == A[i+diff]);
    if(cnt == 0 || (cnt==1 && ((A[0] == A[diff]) || A[diff] == A[N-1]) && N%2)) cout << "TAK\n";
    else cout << "NIE\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}