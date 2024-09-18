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

int N;

void solve(){
    cin >> N;
    int xl = 1e9, xr = -1e9, yl = 1e9, yr = -1e9;
    while(N--){
        int X, Y, H; cin >> X >> Y >> H;
        xl = min(xl, X-H);
        xr = max(xr, X+H);
        yl = min(yl, Y-H);
        yr = max(yr, Y+H);
    }
    cout << (xl+xr)/2 << " " << (yl+yr)/2 << " " << (max({xr-xl, yr-yl})+1)/2 << "\n";
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