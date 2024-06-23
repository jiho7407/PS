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

int N, M, K;
string block[26];
int sqc[200000];
bool pos[200000];

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, K) cin >> block[i];
    string S; cin >> S; reverse(S.begin(), S.end());
    rep(i, 0, N) sqc[i] = S[i] - 'A';
    ll l = M-1, r = M-1;
    while(l > 0 && block[sqc[0]][l-1] == 'R') l--;
    ll ans = r-l+1;
    rep(i, 1, N){
        while(l > 0 && block[sqc[i]][l-1] == 'R') l--;
        while(r >= 0 && block[sqc[i]][r] != 'U') r--;
        ans += r-l+1;
    }
    cout << ans << "\n";
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