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
    ll mx = 0, sum = 0, cnt = 0;
    rep(i, 0, N){
        mx = max(mx, A[i]);
        sum += A[i];
        if(mx*2 == sum) cnt++;
    }
    cout << cnt << '\n';
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