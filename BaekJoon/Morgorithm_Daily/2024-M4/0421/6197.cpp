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

int N, R;
vector<pii> links[100001];
int dist[100001][2];

void solve(){
    cin >> N >> R;
    rep(i, 0, R){
        int A, B, D;
        cin >> A >> B >> D;
        links[A].push_back({B, D});
        links[B].push_back({A, D});
    }
    rep(i, 0, 100001) fill(dist[i], dist[i]+2, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1][0] = 0;
    while(!pq.empty()){
        auto [d, cur] = pq.top(); pq.pop();
        if(cur > dist[cur][1]) continue;
        for(auto [nxt, w] : links[cur]){
            int nd = d + w;
            if(nd < dist[nxt][0]){
                dist[nxt][1] = dist[nxt][0];
                dist[nxt][0] = nd;
                pq.push({nd, nxt});
            }else if(nd < dist[nxt][1]){
                dist[nxt][1] = nd;
                pq.push({nd, nxt});
            }
        }
    }
    cout << dist[N][1] << '\n';
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