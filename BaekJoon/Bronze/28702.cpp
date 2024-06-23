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

int check(string S){
    if(S == "Fizz" || S == "Buzz" || S == "FizzBuzz") return -1;
    return stoi(S);
}

void solve(){
    string a, b, c; cin >> a >> b >> c;
    int ans;
    if(check(a) != -1) ans = check(a)+3;
    else if(check(b) != -1) ans = check(b)+2;
    else ans = check(c)+1;
    if(ans % 3 == 0 && ans % 5 == 0) cout << "FizzBuzz";
    else if(ans % 3 == 0) cout << "Fizz";
    else if(ans % 5 == 0) cout << "Buzz";
    else cout << ans;
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