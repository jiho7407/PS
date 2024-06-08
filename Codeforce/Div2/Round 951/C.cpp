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

ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

void solve(){
    int N; cin >> N;
    vector<ll> lst(N);
    rep(i, 0, N) cin >> lst[i];
    ll LCM = 1;
    rep(i, 0, N) LCM = lcm(LCM, lst[i]);
    ll cnt = 0;
    rep(i, 0, N) cnt += LCM/lst[i];
    if(cnt >= LCM) cout << -1 << '\n';
    else{
        rep(i, 0, N) cout << LCM/lst[i] << ' ';
        cout << '\n';
    }
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