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

string S;

void solve(){
    while(cin >> S){
        cout << S << " [8] = ";
        ll num = 0;
        ll div = 1;
        rep(i, 2, S.size()){
            ll tmp = S[i] - '0';
            div *= (ll)8;
            num *= (ll)8;
            num += tmp;
        }
        cout << "0.";
        while(num){
            num *= 10;
            cout << num / div;
            num %= div;
        }
        cout << " [10]\n";
    }
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