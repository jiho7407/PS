#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    ll N; cin >> N;
    vector<tii> cows;
    rep(i, 0, N){
        ll a, b; cin >> a >> b;
        cows.push_back({a, b, i});
    }
    sort(cows.begin(), cows.end());
    priority_queue<tii, vector<tii>, greater<tii>> pq; // {idx, arrive, cost}
    ll time = 0, ans = 0;
    for(auto [arrive, cost, idx]: cows){
        while(!pq.empty() && time < arrive){
            auto [i, arr, c] = pq.top(); pq.pop();
            ans = max(ans, time - arr);
            time += c;
        }
        if(pq.empty()) time = max(time, arrive);
        pq.push({idx, arrive, cost});
    }
    while(!pq.empty()){
        auto [i, arr, c] = pq.top(); pq.pop();
        ans = max(ans, time - arr);
        time += c;
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