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

const int mxN = 2e5+1;
ll N, X;
ll A[mxN], pfsum[mxN];
map<ll, ll> mp;

void solve(){
    cin >> N >> X;
    rep(i, 1, N+1) cin >> A[i];
    rep(i, 1, N+1) pfsum[i] = pfsum[i-1] + A[i];
    ll ans = 0;
    rep(i, 0, N+1){
        ans += mp[pfsum[i]-X];
        mp[pfsum[i]]++;
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