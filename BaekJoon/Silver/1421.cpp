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

ll N, C, W;
vector<ll> trees;

void solve(){
    cin >> N >> C >> W;
    rep(i, 0, N){
        ll x; cin >> x;
        trees.push_back(x);
    }
    ll ans = 0;
    rep(i, 1, 10001){
        ll ret = 0;
        for(auto t: trees){
            ll get = (t/i)*i*W - (t-1)/i*C;
            ret += max(0LL, get);
        }
        ans = max(ans, ret);
        if(ret == ans) cout << i << " " << ret << "\n";
    }
    cout << ans << "\n";
    return;
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