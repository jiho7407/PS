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

map<int, int> mp;

int calc(int x){
    if(x == 0) return 0;
    if(x < 0) return 1e9;
    if(mp.find(x) != mp.end()) return mp[x];
    mp[x] = 1e9;
    mp[x] = min(mp[x], calc(x - 1) + 1);
    mp[x] = min(mp[x], calc(x - 3) + 1);
    mp[x] = min(mp[x], calc(x - 6) + 1);
    mp[x] = min(mp[x], calc(x - 10) + 1);
    mp[x] = min(mp[x], calc(x - 15) + 1);
    return mp[x];
}

void solve(){
    int N; cin >> N;
    if(N <= 900) cout << calc(N) << '\n';
    else if(N%900 == 5){
        cout << N/15 + 1 << '\n';
    }
    else if(N%900 == 8){
        cout << N/15 + 2 << '\n';
    }
    else{
        cout << calc(N%900) + (N - N%900)/15 << '\n';
    }
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