#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
ll oil[2000];
vector<tii> lines; // x0, x1, y

int calc(int idx, int cx, int cy){
    vector<tuple<double, bool, int>> points; // theta, isend
    rep(i, 0, N){
        if(i == idx) continue;
        auto [x0, x1, y] = lines[i];
        if(y == cy) continue;
        if(y < cy){
            x0 = 2*cx - x0;
            x1 = 2*cx - x1;
            swap(x0, x1);
            y = 2*cy - y;
        }
        points.push_back({atan2(y-cy, x0-cx), 1, i});
        points.push_back({atan2(y-cy, x1-cx), 0, i});
    }
    sort(points.begin(), points.end());
    int cur = oil[idx];
    int ret = oil[idx];
    for(auto [theta, isend, pidx]: points){
        if(isend) cur -= oil[pidx];
        else cur += oil[pidx];
        ret = max(cur, ret);
    }
    return ret;
}

void solve(){
    cin >> N;
    rep(i,0,N){
        int a, b, c;
        cin >> a >> b >> c;
        if(a>b) swap(a,b);
        lines.push_back({a,b,c*-1});
        oil[i] = b-a;;
    }
    int ans = 0;
    rep(i, 0, N){
        ans = max(ans, calc(i, get<0>(lines[i]), get<2>(lines[i])));
        ans = max(ans, calc(i, get<1>(lines[i]), get<2>(lines[i])));
    }
    cout << ans;
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