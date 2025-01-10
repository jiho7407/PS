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
    int ans = 0;
    rep(i, 1, N+1){
        ans += i * (2*i - 1);
    }
    cout << ans << ' ' << 2*N << '\n';
    rep(i, 1, N+1){
        cout << 1 << ' ' << i << ' ';
        for(int j = N; j>=1; j--) cout << j << ' ';
        cout << '\n';
        cout << 2 << ' ' << i << ' ';
        for(int j = N; j>=1; j--) cout << j << ' ';
        cout << '\n';
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