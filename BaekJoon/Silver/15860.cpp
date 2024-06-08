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

int x;
void solve(){
    cout << 2 << endl;
    while(1){
        cin >> x;
        if(x+1 == 99 || x+2 == 99){
            cout << 99 << endl;
            break;
        }
        if((x+2)%3 == 0) cout << x+2 << endl;
        else cout << x+1 << endl;
    }
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