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
vector<ll> pole;

ll calc(ll k){
    ll ret = 0;
    rep(i, 0, N){
        ret += abs(pole[i] - k * i);
    }
    return ret;
}

void solve(){
    cin >> N;
    rep(i,0,N){
        ll x; cin >> x;
        pole.push_back(x);
    }
    ll lo = 0, hi = 1e9;
    while(hi-lo >= 3){
        ll m1 = lo + (hi-lo)/3;
        ll m2 = hi - (hi-lo)/3;
        if(calc(m1) < calc(m2)){
            hi = m2;
        }else{
            lo = m1;
        }
    }
    ll ans = 1e18;
    rep(i,lo,hi+1){
        ans = min(ans, calc(i));
    }
    cout << ans;
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