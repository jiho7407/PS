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
vector<ll> A, B, C, D;
vector<ll> AB, CD;

void solve(){
    cin >> N;
    A.resize(N); B.resize(N); C.resize(N); D.resize(N);
    rep(i, 0, N) cin >> A[i] >> B[i] >> C[i] >> D[i];
    rep(i, 0, N) rep(j, 0, N) AB.push_back(A[i] + B[j]);
    rep(i, 0, N) rep(j, 0, N) CD.push_back(C[i] + D[j]);
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    ll ans = 0;
    for(auto ab: AB){
        auto range = equal_range(CD.begin(), CD.end(), -ab);
        ans += range.second - range.first;
    }
    cout << ans;
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