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
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    ll sum = 0;
    rep(i, 0, N) sum += A[i];
    vector<ll> Ocnt(32, 0);
    rep(i, 0, N) rep(j, 0, 31){
        if(A[i] & (1 << j)) Ocnt[j]++;
    }
    // rep(i, 0, 32) cout << Ocnt[i] << " ";
    ll ans = 0;
    rep(i, 0, N){
        // cout << i << "\n";
        ll ret = 0;
        rep(j, 0, 31){
            if(A[i] & (1 << j)){
                ret += (1 << j) * (N - 2*Ocnt[j]);
            }
        }
        ans = max(ans, ret);
    }
    // cout << sum << " " << ans << '\n';
    cout << sum + ans << '\n';
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