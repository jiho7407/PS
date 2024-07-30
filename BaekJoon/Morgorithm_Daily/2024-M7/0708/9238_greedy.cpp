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

int N;
ld T, mn;
priority_queue<tuple<ld, ld, ld>> pq;

void solve(){
    cin >> T >> N;
    mn = 1e9;
    while(N--){
        ld X; cin >> X;
        mn = min(mn, X);
        pq.push({X, X, 1});
    }
    int ans = 0;
    while(1){
        if(mn/get<0>(pq.top()) > T) break;
        auto [val, X, cnt] = pq.top(); pq.pop();
        ans++; cnt++;
        mn = min(mn, X/cnt);
        pq.push({X/cnt, X, cnt});
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