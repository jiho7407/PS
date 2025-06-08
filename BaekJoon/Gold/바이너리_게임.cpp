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

void solve(){
    string S, T; cin >> S >> T;
    int a = 0, b = 0;
    for(auto x: S) a += x == '1';
    for(auto x: T) b += x == '1';
    if(a%2) a++;
    if(a >= b) cout << "VICTORY";
    else cout << "DEFEAT";
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