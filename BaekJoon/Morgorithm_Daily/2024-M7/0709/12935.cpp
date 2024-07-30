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

void solve(){
    int S; cin >> S;
    if(S == 1){
        cout << 4 << '\n';
        cout << "0 1" << '\n';
        cout << "1 2" << '\n';
        cout << "2 3" << '\n';
        return;
    }
    int sq = 1;
    while((sq+1)*(sq+2) < S) sq++;
    cout << 2*sq + S - sq*(sq+1) + 3 << '\n';
    int idx = 2;
    cout << "0 1" << '\n';
    rep(i, 0, sq) cout << 0 << ' ' << idx++ << '\n';
    rep(i, 0, sq) cout << 1 << ' ' << idx++ << '\n';
    cout << idx-1 << ' ' << idx << '\n';
    rep(i, 0, S - sq*(sq+1)) cout << idx++ << ' ' << idx << '\n';
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