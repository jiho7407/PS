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
    map<int, int> mp;
    rep(i, 0, 7){
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> v;
    for(auto x: mp){
        v.push_back(x.second);
    }
    sort(v.begin(), v.end(), greater<int>());
    if(v[0] >= 3 and v[1] >= 2) cout << "Yes";
    else cout << "No";
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