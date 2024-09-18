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
    int N; cin >> N;
    int ok = 0, ng = N;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        cout << "? " << mid << endl;
        int lamb; cin >> lamb;
        int wolf = mid-lamb;
        if(lamb == wolf){
            cout << "! " << mid << endl;
            return;
        }
        if(lamb > wolf) ok = mid;
        else ng = mid;
    }
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