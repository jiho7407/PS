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

ll N, K;
vector<ll> A;
vector<pll> B;

void solve(){
    cin >> N >> K;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];
    B.push_back({A[K], K});
    rep(i, K, N){
        if(B.back().first < A[i]) B.push_back({A[i], i});
    }

    // for(auto x : B) cout << x.first << ' ' << x.second << '\n';

    ll ans = 1e9;
    rep(i, 0, K){
        ll ok = B.size(), ng = -1;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            if(A[i] < B[mid].first) ok = mid;
            else ng = mid;
        }
        if(ok == B.size()) continue;
        ans = min(ans, B[ok].second - i);
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
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