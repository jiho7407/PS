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

ll N, S, E;
vector<ll> X;

void solve(){
    X.clear();

    cin >> N >> S >> E;
    rep(i, 0, N){
        int a; cin >> a;
        if(a == 1) X.push_back(i);
    }
    ll sz = X.size();

    if(sz <= 1){
        cout << 0 << '\n';
        return;
    }

    ll ans = 1e18;
    ans = min(ans, (sz-1)*E);
    ll mn = X[0] * S * -1;
    rep(j, 1, sz){
        ans = min(ans, (sz - j - 1)*E + (X[j] - j)*S + mn);
        mn = min(mn, j*E + (-X[j] + j) * S);
    }

    cout << ans << '\n';
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