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
vector<ll> lst;

void solve(){
    cin >> N;
    lst.resize(N);
    rep(i, 0, N) cin >> lst[i];
    ll ans = 1e15;
    rep(i, 0, N-1){
        ans = min(ans, max(lst[i], lst[i+1]));
    }
    cout << ans-1 << '\n';
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