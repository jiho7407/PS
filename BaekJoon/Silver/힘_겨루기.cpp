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
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<int> pf(N), sf(N);
    pf[0] = A[0];
    rep(i, 1, N) pf[i] = max(pf[i-1], A[i]);
    sf[N-1] = A[N-1];
    for(int i=N-2; i>=0; i--) sf[i] = max(sf[i+1], A[i]);

    int Lcnt = 0, Rcnt = 0;
    rep(i, 0, N-1){
        if(pf[i] > sf[i+1]) Lcnt++;
        if(pf[i] < sf[i+1]) Rcnt++;
    }
    if(Lcnt == Rcnt) cout << "X";
    else if(Lcnt > Rcnt) cout << "R";
    else cout << "B";
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