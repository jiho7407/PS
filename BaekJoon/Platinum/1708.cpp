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

ll ccw(pll a, pll b, pll c){
    pll ab = {b.first - a.first, b.second - a.second};
    pll ac = {c.first - a.first, c.second - a.second};
    ll ret = ab.first*ac.second - ab.second*ac.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

bool cmp(pll a, pll b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool cmp2(pll a, pll b){
    return ccw(points[0], a, b)>0 || ccw(points[0], a, b)==0 && a < b;
}


void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x, y; cin >> x >> y;
        points.push_back({x, y});
    }
    sort(points.begin(), points.end(), cmp);
    sort(points.begin()+1, points.end(), cmp2);
    vector<pll> hull;
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
    cout << hull.size() << '\n';
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