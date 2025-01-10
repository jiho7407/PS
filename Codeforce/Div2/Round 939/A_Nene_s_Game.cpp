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
    int K, Q; cin >> K >> Q;
    int mn = 1e9;
    rep(i, 0, K){
        int x; cin >> x;
        mn = min(mn, x);
    }
    while(Q--){
        int N; cin >> N;
        cout << min(N, mn-1) << ' ';
    }
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