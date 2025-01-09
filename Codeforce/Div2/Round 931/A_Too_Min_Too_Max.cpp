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

void solve(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());

    int ans = 0;
    ans += A[N-1] - A[0];
    ans += A[N-1] - A[1];
    ans += A[N-2] - A[0];
    ans += A[N-2] - A[1];
    cout << ans << '\n';
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