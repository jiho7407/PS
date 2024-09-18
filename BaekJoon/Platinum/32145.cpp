#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

// Convex Hull
// 볼록 껍질

int N;
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

ll ans = 0;

// make convex hull
void makehull(){
    sort(points.begin(), points.end(), cmp);
    sort(points.begin()+1, points.end(), cmp2);
    if(N == 1){
        hull.push_back(points[0]);
        return;
    }

    hull.push_back(points[0]);
    hull.push_back(points[1]);
    rep(i, 2, N){
        while(hull.size() > 2){
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

// point in Convex Hull
pll toVec(pll a, pll b){
    return {b.first-a.first, b.second-a.second};
}

ll ccw(pll va, pll vb){
    return va.first*vb.second - va.second*vb.first;
}

bool onCvh(vector<pll> &cvh, ll x, ll y){
    if(cvh[0] == (pll){x, y}) return false;
    if(cvh[cvh.size()-1] == (pll){x, y}) return false;
    if(ccw(toVec(cvh[0], cvh[cvh.size()-1]), toVec(cvh[0], {x, y})) == 0) return true;

    int ok = 1, ng = cvh.size()-1;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(ccw(toVec(cvh[0], cvh[mid]), toVec(cvh[0], {x, y})) > 0) ok = mid;
        else ng = mid;
    }
    if((pll){x, y} == cvh[ok]) return false;
    if((pll){x, y} == cvh[ok+1]) return false;
    return ccw(cvh[ok], cvh[ok+1], {x, y}) == 0;
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    makehull();

    bool isline = true;
    rep(i, 0, N-1) if(ccw(points[0], points[i], points[i+1]) != 0) isline = false;

    if(isline) cout << N-1 << '\n';
    else{
        ans += 2*hull.size();
        ans += (N - hull.size() - 1) * 3;
        rep(i, 0, N) if(onCvh(hull, points[i].first, points[i].second)){
            // cout << "point " << points[i].first << ' ' << points[i].second << " is on cvh\n";
            ans--;
        }
        cout << ans << '\n';
    }

    // cout << N << ' ' << hull.size() << '\n';
    // for(auto p: hull) cout << p.first << ' ' << p.second << '\n';
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