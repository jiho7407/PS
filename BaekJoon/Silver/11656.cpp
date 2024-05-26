#include <bits/stdc++.h>
#define ll long long
#define lll __int128
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
    string S;
    vector<string> ans;
    cin >> S;
    rep(i, 0, S.size()){
        ans.push_back(S.substr(i));
    }
    sort(ans.begin(), ans.end());
    for(auto s : ans){
        cout << s << '\n';
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