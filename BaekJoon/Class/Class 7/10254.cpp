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

int N;
vector<pll> points;
vector<pll> hull;

ll ccw(pll a, pll b, pll c){
    pll ab = {b.first - a.first, b.second - a.second};
    pll ac = {c.first - a.first, c.second - a.second};
    ll ret = ab.first*ac.second - ab.second*ac.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

ll cccw(pll a, pll b, pll c, pll d){
    pll ab = {b.first - a.first, b.second - a.second};
    pll cd = {d.first - c.first, d.second - c.second};
    ll ret = ab.first*cd.second - ab.second*cd.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

ll dist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

bool cmp(pll a, pll b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool cmp2(pll a, pll b){
    return ccw(points[0], a, b)>0 || ccw(points[0], a, b)==0 && a < b;
}

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

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x, y; cin >> x >> y;
        points.push_back({x, y});
    }
    if(N == 2) {
        for(auto &p : points) cout << p.first << ' ' << p.second << ' ';
        cout << '\n';
        return;
    }
    makehull();
    ll mx = 0, sz = hull.size();
    pair<pll, pll> ans = {hull[0], hull[1]};
    
    ll bar2 = 1;
    rep(bar1, 0, sz){
        while(1){
            if(cccw(hull[bar1], hull[(bar1+1)%sz], hull[bar2], hull[(bar2+1)%sz]) <= 0) break;
            ll nd = dist(hull[bar1], hull[bar2]);
            if(nd > mx){
                mx = nd;
                ans = {hull[bar1], hull[bar2]};
            }
            bar2 = (bar2+1)%sz;            
        }
        ll nd = dist(hull[bar1], hull[bar2]);
        if(nd > mx){
            mx = nd;
            ans = {hull[bar1], hull[bar2]};
        }
    }

    cout << ans.first.first << ' ' << ans.first.second << ' ' << ans.second.first << ' ' << ans.second.second << '\n';
    
    points.clear();
    hull.clear();
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}