#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int N; cin >> N;
    vector<pair<ll, ll>> vil;
    ll allsum = 0;
    rep(i, 0, N){
        ll a, b; cin >> a >> b;
        vil.push_back({a, b});
        allsum += b;
    }
    sort(vil.begin(), vil.end());
    ll cursum = 0, idx = 0;
    while(cursum*2 < allsum){
        cursum += vil[idx].second;
        idx++;
    }
    cout << vil[idx-1].first << "\n";
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