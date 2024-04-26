#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M, K;
vector<ll> a, b;

void solve(){
    cin >> N >> M >> K;
    a.resize(N);
    b.resize(M);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, M) cin >> b[i];
    // sort(a.begin(), a.end()); 필요없을듯?
    sort(b.begin(), b.end());
    ll ans = 0;
    rep(i, 0, 32){
        if((K >> i & 1) == 0) continue;
        // cout << "cur K: " << (K >> (i+1) << (i+1)) << "\n";
        for(auto A: a){
            ll low = ((A>>i<<i) ^ (K>>(i+1))<<(i+1));
            ll high = low + (1 << i) - 1;
            ans += upper_bound(b.begin(), b.end(), high) - lower_bound(b.begin(), b.end(), low);
            // cout << A << " " << low << " " << high << " " << ans << "\n";
        }
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}