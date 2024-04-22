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

const int INF = 1e9;
int N, M, K;
vector<pii> links[1001];

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, M){
        int A, B, C;
        cin >> A >> B >> C;
        links[A].push_back({B, C});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<priority_queue<int>> dist(N+1);
    pq.push({0, 1});
    dist[1].push(0);
    while(!pq.empty()){
        auto [d, cur] = pq.top(); pq.pop();
        for(auto [nxt, w] : links[cur]){
            if(dist[nxt].size() < K){
                dist[nxt].push(d+w);
                pq.push({d+w, nxt});
            }else if(dist[nxt].top() > d+w){
                dist[nxt].pop();
                dist[nxt].push(d+w);
                pq.push({d+w, nxt});
            }
        }
    }
    rep(i, 1, N+1){
        if(dist[i].size() < K) cout << -1 << '\n';
        else cout << dist[i].top() << '\n';
    }
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