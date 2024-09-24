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
    int K, C; cin >> K >> C;
    while(C--){
        int a, b; cin >> a >> b;
        if(a>b){
            if(2*a-b-2 <= K) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else{
            if(2*b-a-1 <= K) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
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