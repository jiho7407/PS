#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, C;
vector<pii> points;
int root[2000];

int findroot(int x){
    if(root[x] == x) return x;
    return root[x] = findroot(root[x]);
}

void merge(int x, int y){
    x = findroot(x);
    y = findroot(y);
    if(x == y) return;
    if(x < y) root[y] = x;
    else root[x] = y;
}

ll dist(pii a, pii b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve(){
    cin >> N >> C;
    rep(i, 0, N){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    rep(i, 0, N) root[i] = i;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // cost, idx
    rep(i, 0, N) pq.push({dist(points[0], points[i]), i});
    int cnt = 1;
    ll ans = 0;
    while(!pq.empty()){
        auto [cost, idx] = pq.top(); pq.pop();
        if(findroot(0) == findroot(idx)) continue;
        if(cost < C) continue;
        merge(0, idx);
        ans += cost;
        cnt++;
        if(cnt == N) break;
        rep(i, 0, N){
            if(findroot(idx) == findroot(i)) continue;
            pq.push({dist(points[idx], points[i]), i});
        }
    }
    if(cnt != N) cout << -1;
    else cout << ans;
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