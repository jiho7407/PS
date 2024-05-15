#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll minusINF = -1e18;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Line {
    ll m, c;
    ll eval(ll x) { return m * x + c; }
    double intersectX(const Line& other) {
        return (double)(other.c - c) / (m - other.m);
    }
};

deque<Line> hull;

void addLine(ll m, ll c) {
    while (hull.size() >= 2 &&
           hull[hull.size()-2].intersectX(hull.back()) >= hull[hull.size()-2].intersectX({m, c})) {
        hull.pop_back();
    }
    hull.push_back({m, c});
}

ll query(ll x) {
    while (hull.size() >= 2 && hull[0].eval(x) <= hull[1].eval(x)) {
        hull.pop_front();
    }
    return hull[0].eval(x);
}

void solve(){
    int N, C, M;
    cin >> N >> C >> M;
    vector<pair<int, int>> Market(M+1);
    vector<ll> DP(M+1, 0);
    Market[0] = {1, 0};

    for (int i = 1; i <= M; i++) {
        cin >> Market[i].first >> Market[i].second;
    }

    addLine(0, 0);  // 초기 상태

    for (int i = 1; i <= M; i++) {
        ll temp = query(-Market[i].first) + Market[i].second - Market[i].first * C;
        DP[i] = temp;
        addLine(Market[i].first, DP[i] + Market[i].first * C);
    }

    ll ans = *max_element(DP.begin(), DP.end());
    cout << ans << '\n';
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