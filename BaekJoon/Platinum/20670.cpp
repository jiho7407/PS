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

int N, M, K;
vector<pll> cvhA, cvhB;

pll toVec(pll a, pll b){
    return {b.first-a.first, b.second-a.second};
}

ll ccw(pll va, pll vb){
    return va.first*vb.second - va.second*vb.first;
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

    return ccw(toVec(cvh[ok], {x, y}), toVec({x, y}, cvh[ok+1])) < 0;
}

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N){
        ll x, y; cin >> x >> y;
        cvhA.push_back({x, y});
    }
    rep(i, 0, M){
        ll x, y; cin >> x >> y;
        cvhB.push_back({x, y});
    }
    int cnt = 0;
    rep(i, 0, K){
        ll x, y; cin >> x >> y;
        if(inCvh(cvhA, x, y) && !inCvh(cvhB, x, y)) continue;
        cnt++;
    }
    if(cnt == 0) cout << "YES\n";
    else cout << cnt << '\n';
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