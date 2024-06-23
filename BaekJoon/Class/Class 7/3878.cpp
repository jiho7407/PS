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

ll dist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

pll toVec(pll a, pll b){
    return {b.first-a.first, b.second-a.second};
}

ll ccw(pll va, pll vb){
    return va.first*vb.second - va.second*vb.first;
}

// sort by x, y
bool cmp(pll a, pll b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

// sort by angle
bool cmp2(pll a, pll b, vector<pll> &points){
    ll ret = ccw(toVec(points[0], a), toVec(points[0], b));
    return ret>0 || ret==0 && a<b;
    // return ccw(points[0], a, b)>0 || ccw(points[0], a, b)==0 && a < b;
}

// make convex hull
void makehull(vector<pll> &points, vector<pll> &hull){
    sort(points.begin(), points.end(), cmp);
    sort(points.begin()+1, points.end(), [&](pll a, pll b){return cmp2(a, b, points);});
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    rep(i, 2, points.size()){
        while(hull.size() >= 2){
            pll a = hull[hull.size()-2];
            pll b = hull[hull.size()-1];
            pll c = points[i];
            pll AB = toVec(a, b);
            pll AC = toVec(a, c);
            if(ccw(AB, AC) <= 0){
                hull.pop_back();
            }else{
                break;
            }
        }
        hull.push_back(points[i]);
    }
    return;
}

bool inCvh(vector<pll> &cvh, ll x, ll y){
    if(ccw(toVec(cvh[0], cvh[1]), toVec(cvh[0], {x, y})) < 0) return false;
    if(ccw(toVec(cvh[0], cvh[cvh.size()-1]), toVec(cvh[0], {x, y})) > 0) return false;


    int ok = 1, ng = cvh.size()-1;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(ccw(toVec(cvh[0], cvh[mid]), toVec(cvh[0], {x, y})) > 0) ok = mid;
        else ng = mid;
    }

    return ccw(toVec(cvh[ok], {x, y}), toVec({x, y}, cvh[ok+1])) <= 0;
}

bool between(pll a, pll b, pll c){
    if(ccw(toVec(a, b), toVec(a, c)) != 0) return false;
    // b가 가운데 있는지 확인
    return (a<b && b<c) || (c<b && b<a);
}

bool cross(pll A, pll B, pll C, pll D){
    ll CCW1 = ccw(toVec(A, B), toVec(A, C)) * ccw(toVec(A, B), toVec(A, D));
    ll CCW2 = ccw(toVec(C, D), toVec(C, A)) * ccw(toVec(C, D), toVec(C, B));
    if(CCW1 || CCW2) return CCW1 <= 0 && CCW2 <= 0;
    else{
        if(A > B) swap(A, B);
        if(C > D) swap(C, D);
        return A <= D && C <= B;
    }
}

void solve(){
    int N, M; cin >> N >> M;
    vector<pll> pointA, pointB, cvhA, cvhB;
    rep(i, 0, N){
        ll x, y; cin >> x >> y;
        pointA.push_back({x, y});
    }
    rep(i, 0, M){
        ll x, y; cin >> x >> y;
        pointB.push_back({x, y});
    }
    if(N > M) swap(N, M), swap(pointA, pointB);
    makehull(pointA, cvhA);
    makehull(pointB, cvhB);

    // 분리 가능한지 판단. 불가능하면 NO, 가능하면 YES
    if(N == 1){
        if(M == 1) cout << "YES" << '\n';
        else if(M == 2){
            if(between(pointB[0], pointA[0], pointB[1])) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
        else{
            if(inCvh(cvhB, pointA[0].first, pointA[0].second)) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
    }
    else if(N == 2){
        if(M == 2){ // N: A, B / M: C, D
            pll AB = toVec(pointA[0], pointA[1]);
            pll CD = toVec(pointB[0], pointB[1]);
            if(ccw(AB, toVec(pointA[0], pointB[0])) * ccw(AB, toVec(pointA[0], pointB[1])) < 0) cout << "NO\n";
            else if(ccw(CD, toVec(pointB[0], pointA[0])) * ccw(CD, toVec(pointB[0], pointA[1])) < 0) cout << "NO\n";
            else {
                if(between(pointA[0], pointB[0], pointA[1]) || between(pointA[0], pointB[1], pointA[1]) || between(pointB[0], pointA[0], pointB[1]) || between(pointB[0], pointA[1], pointB[1])) cout << "NO\n";
                else cout << "YES\n";
            }
        }
        else{
            if(inCvh(cvhB, pointA[0].first, pointA[0].second) || inCvh(cvhB, pointA[1].first, pointA[1].second)) cout << "NO\n";
            else{
                bool flag = true;
                rep(i, 0, cvhB.size()){
                    if(cross(pointA[0], pointA[1], cvhB[i], cvhB[(i+1)%cvhB.size()])) flag = false;
                }
                if(flag) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    else{
        bool flag = true;
        for(auto p: pointA){
            if(inCvh(cvhB, p.first, p.second)){
                flag = false;
                break;
            }
        }
        for(auto p: pointB){
            if(inCvh(cvhA, p.first, p.second)){
                flag = false;
                break;
            }
        }
        rep(i, 0, cvhA.size()) rep(j, 0, cvhB.size()){
            if(cross(cvhA[i], cvhA[(i+1)%cvhA.size()], cvhB[j], cvhB[(j+1)%cvhB.size()])){
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    pointA.clear();
    pointB.clear();
    cvhA.clear();
    cvhB.clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}