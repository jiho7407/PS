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

ll N;
vector<pll> points;
vector<ld> dists, pfs;

ld dist(pll a, pll b){
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

pair<ld, ld> getPoint(ld L){
    int idx = upper_bound(pfs.begin(), pfs.end(), L) - pfs.begin() - 1;
    ld len = L - pfs[idx];
    ld x = points[idx].first + (points[(idx+1)%N].first - points[idx].first) * len / dists[idx+1];
    ld y = points[idx].second + (points[(idx+1)%N].second - points[idx].second) * len / dists[idx+1];
    return {x, y};
}

ld getArea(vector<pair<ld, ld>> &points){
    ld ret = 0;
    rep(i, 0, points.size()){
        ret += points[i].first * points[(i+1)%points.size()].second - points[(i+1)%points.size()].first * points[i].second;
    }
    return abs(ret) / 2;
}

pair<ld, ld> getAreas(ld L){
    int idx = upper_bound(pfs.begin(), pfs.end(), L) - pfs.begin() - 1;
    pair<ld, ld> point = getPoint(L);

    ld L2 = L + (ld)pfs[N]/2;
    if(L2 >= pfs[N]) L2 -= pfs[N];
    int idx2 = upper_bound(pfs.begin(), pfs.end(), L2) - pfs.begin() - 1;
    pair<ld, ld> point2 = getPoint(L2);

    bool flag = L > L2;
    if(flag){
        swap(L, L2);
        swap(idx, idx2);
        swap(point, point2);
    }

    vector<pair<ld, ld>> points1, points2;

    points1.push_back(point);
    rep(i, idx+1, idx2+1) points1.push_back(points[i]);
    points1.push_back(point2);

    points2.push_back(point2);
    rep(i, idx2+1, N) points2.push_back(points[i]);
    rep(i, 0, idx+1) points2.push_back(points[i]);
    points2.push_back(point);

    ld area1 = getArea(points1);
    ld area2 = getArea(points2);

    if(flag){
        swap(area1, area2);
        swap(points1, points2);
        swap(L, L2);
        swap(idx, idx2);
    }

    // cout << L << ' ' << L2 << ' ' << idx << ' ' << idx2 << '\n';
    return {area1, area2};
}

void printRatio(ld L){
    int idx = upper_bound(pfs.begin(), pfs.end(), L) - pfs.begin() - 1;
    ld len = L - pfs[idx];
    ld ratio = len / dists[idx+1];
    cout << fixed << setprecision(14);
    cout << idx+1 << ' ' << ratio << "\n";

    ld L2 = L + (ld)pfs[N]/2;
    if(L2 >= pfs[N]) L2 -= pfs[N];
    int idx2 = upper_bound(pfs.begin(), pfs.end(), L2) - pfs.begin() - 1;
    ld len2 = L2 - pfs[idx2];
    ld ratio2 = len2 / dists[idx2+1];
    cout << idx2+1 << ' ' << ratio2 << "\n";
}

void solve(){
    cin >> N;
    points.resize(N);
    rep(i, 0, N) cin >> points[i].first >> points[i].second;
    dists.resize(N+1);
    pfs.resize(N+1);
    rep(i, 0, N){
        dists[i+1] = dist(points[i], points[(i+1)%N]);
        pfs[i+1] = pfs[i] + dists[i+1];
    }

    ld ok = 0, ng = (ld)pfs[N]/2;
    pair<ld, ld> tmp = getAreas(0);
    bool flag = false;
    if(tmp.first > tmp.second) flag = true; // flag: 시작할때 기준 왼쪽이 더 크다

    pair<ld, ld> tmp2 = getAreas(ng);
    // cout << ok << ' ' << ng << endl;
    // cout << tmp.first << ' ' << tmp.second << endl;
    // cout << tmp2.first << ' ' << tmp2.second << endl;

    while(1){ 
        ld mid = (ok + ng) / 2;
        pair<ld, ld> areas = getAreas(mid);
        // cout << mid << ' ' << areas.first << ' ' << areas.second << ' ' << areas.first - areas.second << '\n';
        if(abs(areas.first - areas.second) < 1e-7 || abs(areas.first - areas.second) < 1e-7 * (areas.first + areas.second)){
            cout << "YES\n";
            printRatio(mid);
            return;
        }
        if(areas.first > areas.second){
            if(flag) ok = mid;
            else ng = mid;
        }
        else{
            if(flag) ng = mid;
            else ok = mid;
        }
    }

    cout << "NO\n";

    // ok = 0, ng = pfs[N];
    // while(ng - ok > 0.00000001){ 
    //     ld mid = (ok + ng) / 2;
    //     pair<ld, ld> areas = getAreas(mid);
    //     if(abs(areas.first - areas.second) < 0.00000001){
    //         cout << "YES\n";
    //         printRatio(mid);
    //         return;
    //     }
    //     if(areas.first < areas.second) ng = mid;
    //     else ok = mid;
    // }


    // for(int i = 0; i<10; i++){
    //     ld L = pfs[N] / (ld)10 * i;
    //     pair<ld, ld> areas = getAreas(L);
    //     // cout << fixed << setprecision(14);
    //     cout << L << ' ' << areas.first << ' ' << areas.second << ' ' << areas.first - areas.second << '\n';
    //     cout << endl;
    // }

    // cout << "NO\n";
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