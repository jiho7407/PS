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

void solve(){
    int K; cin >> K; K--;
    rep(i, 0, K/2){
        cout << i+1 << " ";
        rep(j, 1, K/2){
            cout << (i+j)%K+1 << " ";
            cout << (i-j+K)%K+1 << " ";
        }
        cout << (i+K/2)%K + 1 << " ";
        cout << K+1 << " ";
        cout << "\n";
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