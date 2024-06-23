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
    string S; cin >> S;
    int lower = 0, upper = 0;
    rep(i, 0, S.size()){
        if(S[i] - 'a' >= 0) lower++;
        else upper++;
    }
    if(lower > upper) transform(S.begin(), S.end(), S.begin(), ::tolower);
    else transform(S.begin(), S.end(), S.begin(), ::toupper);
    cout << S << '\n';
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