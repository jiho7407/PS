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

ll N;
ll mod = 1e9+7;

ll modpow(ll A, ll B){
    if(B <= 0) return 1;
    if(B == 1) return A;
    ll tmp = modpow(A, B/2);
    if(B % 2 == 0) return (tmp * tmp) % mod;
    else return (((tmp * tmp) % mod) * A) % mod;
}

void solve(){
    cin >> N;
    cout << modpow(2, N-2) << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}