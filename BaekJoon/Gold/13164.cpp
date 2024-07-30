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
ll A[300000];
priority_queue<ll> pq;

void solve(){
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    rep(i, 1, N) pq.push(A[i]-A[i-1]);
    ll ans = A[N-1] - A[0];
    rep(i, 0, K-1){
        ans -= pq.top();
        pq.pop();
    }
    cout << ans << '\n';
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