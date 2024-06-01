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

const ll mod = 1e9+7;
const ll p = 31;

void solve(){
    int N; cin >> N;
    char a;
    ll hash1 = 0, hash2 = 0;
    ll rp = 1;
    while(cin >> a){
        hash1 = (hash1*p + a)%mod;
        hash2 = (hash2 + a*rp)%mod;
        rp = (rp*p)%mod;
    }
    if(hash1 == hash2) cout << "TAK";
    else cout << "NIE";
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