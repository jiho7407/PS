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

ll N, M;
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<ll> v;

void solve(){
    cin >> N >> M;
    rep(i, 0, N){
        ll x; cin >> x;
        pq.push(x);
    }
    rep(i, 0, M){
        ll x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    rep(i, 0, M){
        ll cur = v[i];
        while(!pq.empty() && pq.top() < cur){
            pq.pop();
        }
        if(pq.empty()){
            cout << -1;
            return;
        }
        ans += pq.top();
        pq.pop();
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