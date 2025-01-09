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

ll fact(ll n){
    ll ans = 1;
    rep(i, 1, n+1) ans *= i;
    return ans;
}

ll getval(ll n, ll d){
    ll ans = 0;
    n = fact(n);
    while(n--){
        ans *= 10;
        ans += d;
    }
    return ans;
}

void solve(){
    ll N, D; cin >> N >> D;
    vector<ll> ans;
    ans.push_back(1);

    if(N >= 3 || fact(N)*D%3 == 0) ans.push_back(3);
    if(D == 5) ans.push_back(5);

    if(N >= 3 || getval(N, D)%7 == 0) ans.push_back(7);

    if(N >= 6 || fact(N)*D%9 == 0) ans.push_back(9);


    for(auto x: ans) cout << x << ' ';
    cout << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}