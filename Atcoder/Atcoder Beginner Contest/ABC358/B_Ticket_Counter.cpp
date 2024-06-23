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
    int N, A; cin >> N >> A;
    vector<int> lst(N);
    rep(i, 0, N) cin >> lst[i];
    int time = 0;
    rep(i, 0, N){
        time = max(time, lst[i]);
        cout << time + A << "\n";
        time += A;
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