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

const double PI = acos(-1);
int N;
vector<pair<ll, ll>> points;

void solve(){
    cin >> N;
    points.resize(N);
    rep(i, 0, N){
        cin >> points[i].first >> points[i].second;
    }
    ll mx = 0;
    vector<pair<ll, ll>> far;
    for(auto [x, y]: points){
        ll dist = x*x + y*y;
        if(dist < mx) continue;
        if(dist > mx){
            mx = dist;
            far.clear();
        }
        far.push_back({x, y});
    }
    vector<double> angles;
    for(auto [x, y]: far){
        double angle = atan2(y, x);
        angles.push_back(angle/PI*180);
    }
    if(angles.size() == 1){
        cout << "360.0000000000";
        return;
    }
    sort(angles.begin(), angles.end());

    double ans = 0;
    rep(i, 0, angles.size()){
        double diff = angles[(i+1)%angles.size()] - angles[i];
        if(diff < 0) diff += 360;
        ans = max(ans, diff);
    }
    cout << fixed << setprecision(10) << ans;
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