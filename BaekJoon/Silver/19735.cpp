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
    if(N == 1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    if(N%2){
        cout << 3 << '\n';
        cout << "-++";
        rep(i, 0, N-3){
            if(i%2) cout << '-';
            else cout << '+';
        }
        cout << '\n';
    }
    else{
        cout << 1 << '\n';
        rep(i, 0, N){
            if(i%2) cout << '-';
            else cout << '+';
        }
        cout << '\n';
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