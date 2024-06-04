#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, Q;
vector<pll> points, cvh;
vector<ll> ans;

ll CCW(pll a, pll b, pll c){
    ll result = 1LL*(b.first-a.first)*(c.second-b.second)
                -1LL*(b.second-a.second)*(c.first-b.first);
    if(result>0) return 1;
    else if (result==0) return 0;
    else return -1;
}

bool cmp1(pll a, pll b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

bool cmp2(pll &a, pll &b){
    ll temp = CCW(points[0], a, b);
    if(temp != 0) return temp>0;
    return a.second < b.second || a.second == b.second && a.first < b.first;
}

void solve(){
    ll N; cin >> N;
    points.push_back({0, 0});
    rep(i, 0, N){
        ll x; cin >> x;
        if(i == 0) points.push_back({1, x});
        else points.push_back({i+1, points.back().second+x});
    }
    ans.resize(N+10);
    fill(ans.begin(), ans.end(), 0);
    for(ll i = 0; i<points.size(); i++){
        while(cvh.size() >= 1 && CCW(cvh[cvh.size()-2], cvh[cvh.size()-1], points[i]) == -1){ cvh.pop_back(); }
        if(i != 0) ans[i] = points[i].first - cvh.back().first;
        cvh.push_back(points[i]);
    }

    ll Q; cin >> Q;
    while(Q--){
        ll x; cin >> x; x--;
        cout << ans[x] << " ";
    }
    cout << "\n";

    points.clear();
    cvh.clear();
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