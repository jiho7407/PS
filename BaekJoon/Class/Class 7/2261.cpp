#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<pii> points;

ll dist(pii a, pii b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

struct cmp{
    bool operator()(const pii& a, const pii& b) const{
        return a.second < b.second;
    }
};

void solve(){
    cin >> N;
    points.resize(N);
    rep(i, 0, N) cin >> points[i].first >> points[i].second;
    sort(points.begin(), points.end());
    if(N <= 10){
        ll ans = 1e18;
        rep(i, 0, N) rep(j, i+1, N) ans = min(ans, dist(points[i], points[j]));
        cout << ans << '\n';
        return;
    }

    ll dsq = dist(points[0], points[1]);
    set<pii, cmp> Q = {points[0], points[1]};
    int left = 0;
    rep(i, 2, N){
        auto cur = points[i];
        while(left < i){
            auto p = points[left];
            ll dx = cur.first - p.first;
            if(dx*dx > dsq){
                Q.erase(p);
                left++;
            }
            else break;
        }
        ll d = (ll)sqrt(dsq) + 1;
        auto lower = Q.lower_bound({-100000, cur.second - d});
        auto upper = Q.upper_bound({100000, cur.second + d});
        for(auto it = lower; it != upper; it++) dsq = min(dsq, dist(cur, *it));
        Q.insert(cur);
    }
    cout << dsq << '\n';
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