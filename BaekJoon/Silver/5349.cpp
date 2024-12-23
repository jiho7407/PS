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

set<string> s, ans;

void solve(){
    while(1){
        string S;
        cin >> S;
        if(S=="000-00-0000") break;
        if(!s.insert(S).second) ans.insert(S);
    }
    for(auto x:ans) cout << x << '\n';
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