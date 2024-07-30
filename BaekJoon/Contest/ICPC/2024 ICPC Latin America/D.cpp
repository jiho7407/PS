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

ll N;
map<int, int> primes;

void solve(){
    cin >> N;
    ll mod = 2;
    while(mod*mod <= N){
        while(N % mod == 0){
            primes[mod]++;
            N /= mod;
        }
        mod++;
    }
    if(N > 1) primes[N]++;
    if(primes.size() == 1 && primes.begin()->second %2 == 1) cout << "Y";
    else if(primes.size() == 2 && (primes.begin()->second + (++primes.begin())->second) == 2) cout << "Y";
    else cout << "N";
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