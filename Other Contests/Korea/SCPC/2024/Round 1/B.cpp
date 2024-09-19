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

int N;
int A[300000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    sort(A, A+N);
    ll ans = 0;
    rep(i, 0, N/4) ans -= A[i];
    rep(i, N/4*3, N) ans += A[i];
    cout << ans*2 << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}