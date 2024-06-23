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

ll N, P, K;
map<ll, ll> p;

void solve(){
    cin >> N >> P >> K;
    rep(i, 0, N){
        ll a; cin >> a;
        ll res = a*a%P*a%P;
        res -= K*a%P;
        res += P; res %= P;
        p[res]++;
    }
    ll ans = 0;
    for(auto [k, v]: p){
        ans += v*(v-1)/2;
    }
    cout << ans << '\n';
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