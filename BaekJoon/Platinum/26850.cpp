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

unordered_set<ll> s;

void solve(){
    ll N, M; cin >> N >> M;
    while(M--){
        ll x; cin >> x;
        s.insert(x);
    }
    
    ll ans = 0;
    ll lv = 1;
    rep(n, 1, N+1){
        if(n >= lv*2) lv *= 2;
        if(s.find(n) != s.end()) continue;
        ll ret = (n-lv)*2;
        // cout << n << ' ' << ret << '\n';
        ans += ret;
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