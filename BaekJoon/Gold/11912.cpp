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

ll N, K, D;
priority_queue<ll> pq;

void solve(){
    cin >> N >> K >> D;
    vector<ll> P(K);
    rep(i, 0, K) cin >> P[i];
    rep(i, 1, K) pq.push(P[i] - P[i-1]-1);
    ll ans = 0;
    ll tmp = 0;
    if(D >= 2){
        ans = max(ans, (tmp + P[0] - 1) + (N - P[K-1]));
    }
    if(D >= 1){
        ans = max(ans, tmp + (P[0] - 1));
        ans = max(ans, tmp + (N - P[K-1]));
    }
    ans = max(ans, tmp);
    while(!pq.empty()){
        if(D < 2) break;

        auto cnt = pq.top(); pq.pop();
        tmp += cnt;
        D -= 2;

        if(D >= 2){
            ans = max(ans, (tmp + P[0] - 1) + (N - P[K-1]));
        }
        if(D >= 1){
            ans = max(ans, tmp + (P[0] - 1));
            ans = max(ans, tmp + (N - P[K-1]));
        }
        ans = max(ans, tmp);
    }

    cout << ans;
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