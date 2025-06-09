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
    ll N; cin >> N;

    rep(i, 0, 10){
        int ret = 0;
        rep(j, 0, 7) ret += max(0, i-j);
        if(ret >= N){
            cout << i;
            return;
        }
    }

    ll ok = 1e18, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) >> 1;
        if(mid * 7 < N) ng = mid;
        else ok = mid;
    }
    cout << ok+3;
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