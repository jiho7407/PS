#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, C;
vector<pll> polygon[1010];
vector<pll> points;
map<pll, int> mp;
vector<int> links[1010];
bool used[1010];
int idx = 0, polyidx = 0;
vector<pll> cows;
bitset<1010> cowresult[1010];

pll ptv(pll a, pll b){
    return {b.first - a.first, b.second - a.second};
}

int ccw(pll a, pll b){
    ll ret = a.first*b.second - a.second*b.first;
    if(ret > 0) return 1;
    else if(ret == 0) return 0;
    else return -1;
}

bool inpoly(pll p, vector<pll> &poly){
    int cnt = 0;
    for(int i = 0; i<poly.size(); i++){
        pll a = poly[i], b = poly[(i+1)%poly.size()];
        if(a.second > b.second) swap(a, b);
        if(ccw(ptv(a, b), ptv(a, p)) == 0){
            if(min(a.first, b.first) <= p.first && p.first <= max(a.first, b.first) && a.second <= p.second && p.second <= b.second) return true;
        }
        if(a.second <= p.second && p.second < b.second){ 
            if((b.second - a.second)*(p.first - a.first) < (p.second - a.second)*(b.first - a.first)) cnt++;
        }
    }
    return cnt%2 == 1;
}

void solve(){
    cin >> N >> C;
    for(int i = 0; i<N; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(mp.find({x1, y1}) == mp.end()){
            points.push_back({x1, y1});
            mp[{x1, y1}] = idx++;
        }
        if(mp.find({x2, y2}) == mp.end()){
            points.push_back({x2, y2});   
            mp[{x2, y2}] = idx++;
        }
        links[mp[{x1, y1}]].push_back(mp[{x2, y2}]);
        links[mp[{x2, y2}]].push_back(mp[{x1, y1}]);
    }
    fill(used, used+idx, false);
    for(int i = 0; i<idx; i++){
        if(used[i]) continue;
        stack<int> stk;
        stk.push(i);
        used[i] = true;
        while(!stk.empty()){
            int cur = stk.top();
            polygon[polyidx].push_back(points[cur]);
            stk.pop();
            for(auto &nxt : links[cur]){
                if(used[nxt]) continue;
                stk.push(nxt);
                used[nxt] = true;
            }
        }
        polyidx++;
    }
    for(int i = 0; i<C; i++){
        ll x, y;
        cin >> x >> y;
        for(int j = 0; j<polyidx; j++){
            if(inpoly({x, y}, polygon[j])){
                cowresult[i].set(j);
            }
        }
    }

    // for(int i = 0; i<C; i++) cout << cowresult[i] << "\n";

    int ans = 0;
    for(int i = 0; i<C; i++){
        int temp = 0;
        for(int j = 0; j<C; j++){
            if(cowresult[i] == cowresult[j]) temp++;
        }
        ans = max(ans, temp);
    }
    cout << ans;

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