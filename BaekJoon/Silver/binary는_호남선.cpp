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
    int ans[2];
    cout << "? " << 1 << endl;
    cin >> ans[0];
    cout << "? " << N << endl;
    cin >> ans[1];

    if(ans[0] == ans[1]){
        cout << "! " << 0 << endl;
    }
    else if(ans[0] < ans[1]){
        cout << "! " << 1 << endl;
    }
    else{
        cout << "! " << -1 << endl;
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