#include <bits/stdc++.h>
#define int long long
#define ll __int128
// #define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll cpd(pll a, pll b){
    return a.first*b.second - a.second*b.first;
}

ll den;

pll polygon_centroid(vector<pll> &polygon){
    ll cx = 0, cy = 0, area2 = 0;
    rep(i, 0, polygon.size()){
        ll tri_area = cpd(polygon[i], polygon[(i+1)%(ll)polygon.size()]);
        cx += (polygon[i].first + polygon[(i+1)%(ll)polygon.size()].first) * tri_area;
        cy += (polygon[i].second + polygon[(i+1)%(ll)polygon.size()].second) * tri_area;
        area2 += tri_area;
    }
    den = area2*3;
    return {cx, cy};
}

// AB x AC
int ccw(pll a, pll b, pll c){
    pll ab = {b.first - a.first, b.second - a.second};
    pll ac = {c.first - a.first, c.second - a.second};
    ll ret = ab.first*ac.second - ab.second*ac.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

ll calc(ll cnt){
    return cnt*(cnt-1)*(cnt-2)/6;
}

ll N;
vector<pll> polygon;
pll cent;

bool cmp(pll a, pll b){
    pll oa = {a.first - cent.first, a.second - cent.second};
    pll ob = {b.first - cent.first, b.second - cent.second};
    if((oa.first<0)^(ob.first<0)) return oa.first > ob.first;
    if(int t = ccw(cent, a, b)) return t > 0;
    return (oa.first*oa.first + oa.second*oa.second) < (ob.first*ob.first + ob.second*ob.second);
}

void solve(){
    int tmp; cin >> tmp;
    ll N = tmp;
    polygon.resize(N);
    rep(i, 0, N){
        int a, b; cin >> a >> b;
        polygon[i] = {a, b};
    }
    cent = polygon_centroid(polygon);
    rep(i, 0, N){
        polygon[i].first *= den;
        polygon[i].second *= den;
    }

    rep(i, 0, N) if(polygon[i] == cent){
        polygon.erase(polygon.begin()+i);
        N--;
        break;
    }

    int ans = calc(N);
    sort(polygon.begin(), polygon.end(), cmp);

    ll i = 0, j = 1;
    while(i < N){
        while(ccw(cent, polygon[i], polygon[j]) >= 0) j = (j+1)%N;
        if(ccw(cent, polygon[i], polygon[(j+N-1)%N]) == 0) j = (j+N-1)%N;
        ll cnt = (i-j+N+1)%N;
        ans -= (cnt-1)*(cnt-2)/2;
        i++;
    }

    cout << ans << '\n';
}

signed main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}