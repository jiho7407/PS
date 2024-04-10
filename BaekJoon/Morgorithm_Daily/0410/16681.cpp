#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll INF = 1e18;
ll N, M, D, E;
ll H[100001];
vector<pll> links[100001];
ll dist1[100001], dist2[100001];

void dijkstra(ll start, ll *dist){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0LL, start});
    dist[start] = 0;
    while(!pq.empty()){
        auto [curDist, cur] = pq.top(); pq.pop();
        if(dist[cur] < curDist) continue;
        for(auto [goal, cost] : links[cur]){
            if(H[goal] <= H[cur]) continue;
            ll nextDist = cost + curDist;
            if(dist[goal] > nextDist){
                dist[goal] = nextDist;
                pq.push({nextDist, goal});
            }
        }
    }
}

void solve(){
    cin >> N >> M >> D >> E;
    for(ll i=1; i<=N; i++){
        cin >> H[i];
    }
    for(ll i=0; i<M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        links[a].push_back({b, c});
        links[b].push_back({a, c});
    }
    fill(dist1, dist1+N+1, INF);
    fill(dist2, dist2+N+1, INF);
    dijkstra(1, dist1);
    dijkstra(N, dist2);
    ll ans = INF * -1;
    for(ll i=2; i<N; i++){
        if(dist1[i] == INF || dist2[i] == INF) continue;
        ll tmp = H[i] * E - (dist1[i] + dist2[i]) * D;
        ans = max(ans, tmp);
    }
    if(ans == INF*-1) cout << "Impossible";
    else cout << ans;

    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}