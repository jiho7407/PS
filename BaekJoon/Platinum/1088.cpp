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

int N, M;
ld mn, mx;
priority_queue<tuple<ld, ld, ld>> pq;

void solve(){
    cin >> N;
    mn = 1e9, mx = 0;
    rep(i, 0, N){
        ld X; cin >> X;
        mn = min(mn, X), mx = max(mx, X);
        pq.push({X, X, 1});
    }
    ld ans = mx-mn;

    cin >> M;
    while(M--){
        auto [val, X, cnt] = pq.top(); pq.pop();
        cnt++;
        mn = min(mn, X/cnt);
        pq.push({X/cnt, X, cnt});
        ans = min(ans, get<0>(pq.top())-mn);
    }
    cout << fixed << setprecision(12) << ans << '\n';
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