#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
map<int, int> mp;

void solve(){
    cin >> N;
    rep(i, 0, N){
        int x; cin >> x;
        mp[x]++;
    }
    cin >> M;
    rep(i, 0, M){
        int x; cin >> x;
        cout << mp[x] << ' ';
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