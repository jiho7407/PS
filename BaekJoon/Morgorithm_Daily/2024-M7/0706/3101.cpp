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

int N, K;
string S;

ll calc(int x, int y){
    if(x+y >= N) return (ll)N*N - calc(N-x-1, N-y-1) + 1;
    ll ret = 1;
    ll idx = x + y;
    ret += (idx+1) * idx / 2;
    if(idx%2) ret += x;
    else ret += (idx - x);
    return ret;
}

void solve(){
    cin >> N >> K >> S;
    ll ans = 1;
    int cx = 0, cy = 0;
    rep(i, 0, K){
        char op = S[i];
        if(op == 'U') cx--;
        else if(op == 'D') cx++;
        else if(op == 'L') cy--;
        else cy++;
        ans += calc(cx, cy);
    }
    cout << ans;
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