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

int N, T;
vector<pair<pii, pii>> stars;
vector<pll> points;
vector<pll> hull;

// AB x AC
ll ccw(pll a, pll b, pll c){
    pll ab = {b.first - a.first, b.second - a.second};
    pll ac = {c.first - a.first, c.second - a.second};
    ll ret = ab.first*ac.second - ab.second*ac.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

// AB x CD
ll cccw(pll a, pll b, pll c, pll d){
    pll ab = {b.first - a.first, b.second - a.second};
    pll cd = {d.first - c.first, d.second - c.second};
    ll ret = ab.first*cd.second - ab.second*cd.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

// AB^2
ll dist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

// sort by x, y
bool cmp(pll a, pll b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

// sort by angle
bool cmp2(pll a, pll b){
    return ccw(points[0], a, b)>0 || ccw(points[0], a, b)==0 && a < b;
}

// make convex hull
void makehull(){
    sort(points.begin(), points.end(), cmp);
    sort(points.begin()+1, points.end(), cmp2);
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    rep(i, 2, N){
        while(hull.size() >= 2){
            pll a = hull[hull.size()-2];
            pll b = hull[hull.size()-1];
            pll c = points[i];
            if(ccw(a, b, c) <= 0){
                hull.pop_back();
            }else{
                break;
            }
        }
        hull.push_back(points[i]);
    }
    return;
}

// rotating calipers
ll rotating_calipers(){
    ll mx = 0, sz = hull.size();
    ll bar2 = 1;
    rep(bar1, 0, sz){
        while(1){
            if(cccw(hull[bar1], hull[(bar1+1)%sz], hull[bar2], hull[(bar2+1)%sz]) <= 0) break;
            mx = max(mx, dist(hull[bar1], hull[bar2]));
            bar2 = (bar2+1)%sz;            
        }
        ll nd = dist(hull[bar1], hull[bar2]);
        mx = max(mx, nd);
    }
    return mx;
}

ll calc(ll k){
    rep(i, 0, N){
        auto [x, y] = stars[i].first;
        auto [dx, dy] = stars[i].second;
        points.push_back({x + k*dx, y + k*dy});
    }
    makehull();
    ll ret = rotating_calipers();
    points.clear();
    hull.clear();
    return ret;
}

void solve(){
    cin >> N >> T;
    rep(i, 0, N){
        ll x, y, dx, dy; cin >> x >> y >> dx >> dy;
        stars.push_back({{x, y}, {dx, dy}});
    }
    ll lo = 0, hi = T;
    while(hi-lo >= 3){
        ll m1 = lo + (hi-lo)/3;
        ll m2 = hi - (hi-lo)/3;
        ll tmp1 = calc(m1);
        ll tmp2 = calc(m2);
        if(tmp1 <= tmp2){
            hi = m2;
        }
        else{
            lo = m1;
        }
    }
    ll idx = 0;
    ll ans = 1e18;
    rep(i, lo, hi+1){
        if(calc(i) < ans){
            ans = calc(i);
            idx = i;
        }
    }
    cout << idx << '\n';
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