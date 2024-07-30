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
int A[50], B[50];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    B[0] = A[0];
    rep(i, 1, N) B[i] = max(B[i-1], A[i]);
    ll ans = 0;
    rep(i, 0, N){
        map<int, ll> mp;
        rep(j, 0, i) if(A[j] < A[i]) mp[A[j]]++;
        if(i == 0 || B[i-1] <= A[i]) continue;
        ll ret = 1;
        for(auto [k, v]: mp) ret *= (v+1);
        ans += ret;
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