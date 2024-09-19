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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
typedef Point P;
T x, y;
explicit Point(T x=0, T y=0) : x(x), y(y) {}
bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y);
}
bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y);
}
P operator+(P p) const { return P(x+p.x, y+p.y); }
P operator-(P p) const { return P(x-p.x, y-p.y); }
P operator*(T d) const { return P(x*d, y*d); }
P operator/(T d) const { return P(x/d, y/d); }
T dot(P p) const { return x*p.x + y*p.y; }
T cross(P p) const { return x*p.y - y*p.x; }
T cross(P a, P b) const { return (a-*this).cross(b-*this); }
T dist2() const { return x*x + y*y; }
ld dist() const { return sqrt((ld)dist2()); }
// angle to x-axis in interval [-pi, pi]
ld angle() const { return atan2(y, x); }
P unit() const { return *this/dist(); } // makes dist()=1
P perp() const { return P(-y, x); } // rotates +90 degrees
P normal() const { return perp().unit(); }
// returns point rotated 'a' radians ccw around the origin
P rotate(ld a) const {
return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
friend ostream& operator<<(ostream& os, P p) {
return os << "(" << p.x << "," << p.y << ")"; }
};


typedef Point<ld> P;
ld closest(vector<P> v) {
    assert(v.size() > 1);
    set<P> S;
    sort(v.begin(), v.end(), [](P a, P b) { return a.y < b.y; });
    pair<ld, pair<P, P>> ret{1e18, {P(), P()}};
    int j = 0;
    for (P p : v) {
    P d{1 + (ld)sqrt(ret.first), 0};
    while (v[j].y <= p.y - d.x) S.erase(v[j++]);
    auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);
    for (; lo != hi; ++lo)
    ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
    S.insert(p);
    }
    return sqrt(ret.first);
}

ld dist(P a, P b){
    return (a-b).dist();
}

int N;
vector<tuple<ll, ll, ll>> planets;
multiset<ll> mst;

bool cmp(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b){
    return get<2>(a) < get<2>(b);
}

const ld PI = acos(-1);

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x, y, z;
        cin >> x >> y >> z;
        planets.push_back({x, y, z});
    }
    sort(planets.begin(), planets.end(), cmp);

    ld ans = 1e18;

    // 두 행성의 공전주기가 다른 경우
    for(auto [x, y, z]: planets) mst.insert(x);
    for(int i = 0, j; i<N; i = j){
        j = i;
        while(j < N && get<2>(planets[j]) == get<2>(planets[i])){
            mst.erase(mst.find(get<0>(planets[j])));
            j++;
        }
        for(int k = i; k < j; k++){
            auto [R, theta, T] = planets[k];
            auto it = mst.upper_bound(R);
            if(it != mst.end()) ans = min(ans, (ld)(*it - R));
            if(it != mst.begin()) ans = min(ans, (ld)(R - *prev(it)));
        }
        for(int k = i; k < j; k++) mst.insert(get<0>(planets[k]));
    }

    // 두 행성의 공전주기가 같은 경우
    for(int i = 0, j; i<N; i = j){
        vector<P> V;
        j = i;
        while(j < N && get<2>(planets[j]) == get<2>(planets[i])){
            auto [R, theta, T] = planets[j];
            ld rad = (ld)PI*(ld)theta/(ld)180000;
            V.push_back(P((ld)R*cos(rad), (ld)R*sin(rad)));
            j++;
        }
        if(V.size() <= 1) continue;
        ans = min(ans, closest(V));
    }

    cout << fixed << setprecision(10) << ans;
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