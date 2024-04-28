#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    ll N, K; cin >> N >> K;
    ll sum = 0, ans = 0;
    multiset<ll> ms;
    rep(i, 0, N){
        ll x; cin >> x;
        ms.insert(x);
        sum += x;
    }
    while(K < sum){
        auto it = ms.upper_bound(K);
        if(it == ms.begin()){
            cout << -1 << '\n';
            return;
        }
        it--;
        ll x = *it;
        ms.erase(it);
        sum -= x;
        K += x;
        ans += 1;
    }
    cout << ans << "\n";
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