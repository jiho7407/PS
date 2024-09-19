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
int A[5001];
int fb[5001], fbpfs[5001];

void solve(){
    cin >> N;
    rep(i, 1, N+1) cin >> A[i];

    rep(i, 1, N+1){
        fb[i] = 0;
        rep(j, i+1, N+1) if(A[i] > A[j]) fb[i]++;
    }

    ll ans = 0;
    rep(c, 1, N+1){
        rep(i, 1, c+1) if(A[i] > A[c]) fb[i]--;

        fbpfs[0] = 0;
        rep(i, 1, N+1) fbpfs[i] = fbpfs[i-1] + fb[i];

        rep(a, 1, c) if(A[a] < A[c]) ans += fbpfs[c-1] - fbpfs[a];
    }
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