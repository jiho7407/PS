#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, K;
vector<ll> rows, cols;

bool check(ll k){
    ll cost = 0;
    vector<ll> tmpr;
    for(auto r : rows){
        tmpr.push_back(r);
        tmpr.push_back(r-k);
    }
    sort(tmpr.begin(), tmpr.end());
    for(auto r: rows){
        if(r < tmpr[N]) cost += tmpr[N] - r;
        if(r > tmpr[N] + k) cost += r - (tmpr[N] + k);
    }
    vector<ll> tmpc;
    for(auto c : cols){
        tmpc.push_back(c);
        tmpc.push_back(c-k);
    }
    sort(tmpc.begin(), tmpc.end());
    for(auto c: cols){
        if(c < tmpc[N]) cost += tmpc[N] - c;
        if(c > tmpc[N] + k) cost += c - (tmpc[N] + k);
    }
    return cost <= K;
}

void solve(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        rows.push_back(y);
        cols.push_back(x);
    }
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    ll ok = 1e9, ng = -1;
    while(ok-ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
    return;
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