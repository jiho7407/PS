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

ll N, B, S, R;
vector<pii> links[5000], r_links[5000];
ll dist[5000], r_dist[5000], pfsum[5000];
ll DP[5000][5000]; // DP[G][i] == G개의 그룹으로 i번째까지 봤을 때 최소 비용
ll OPT[5000][5000]; // OPT[G][i] == DP[G][i] 일때 최소 비용을 만족하는 j값

ll C(ll k, ll j){
    return (j-k-1)*(pfsum[j]-pfsum[k]);
}

void DnC(ll t, ll s, ll e, ll p, ll q){
    // min(s <= j <= e) DP[t][j] + C(j, i)를 반환
    // 이때 p <= j <= q

    if(s > e) return;

    ll m = (s+e)>>1;

    DP[t][m] = 1e18; // INF
    OPT[t][m] = -1;
    // 1. DP[t][m], OPT[t][m] 계산
    rep(k, p, q+1){
        ll val = DP[t-1][k] + C(k, m);
        if(DP[t][m] > val){
            DP[t][m] = val;
            OPT[t][m] = k;
        }
    }

    // 2. 분할 정복
    DnC(t, s, m-1, p, OPT[t][m]);
    DnC(t, m+1, e, OPT[t][m], q);
    
    return;
}

void solve(){
    cin >> N >> B >> S >> R;
    while(R--){
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        links[u].push_back({v, w});
        r_links[v].push_back({u, w});
    }
    fill_n(&dist[0], 5000, 1e9);
    fill_n(&r_dist[0], 5000, 1e9);
    dist[B] = r_dist[B] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, B});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(dist[u] < d) continue;
        for(auto [v, w]: links[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    pq.push({0, B});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(r_dist[u] < d) continue;
        for(auto [v, w]: r_links[u]){
            if(r_dist[v] > r_dist[u] + w){
                r_dist[v] = r_dist[u] + w;
                pq.push({r_dist[v], v});
            }
        }
    }
    rep(i, 0, B) dist[i] += r_dist[i];
    sort(dist, dist+B);
    fill_n(&pfsum[0], 5000, 0);
    rep(i, 1, B+1) pfsum[i] = pfsum[i-1] + dist[i-1];

    rep(i, 0, B+1) DP[1][i] = C(0, i);
    rep(i, 0, B+1) OPT[1][i] = 0;
    rep(i, 2, S+1) DnC(i, i, B, 0, B);

    cout << DP[S][B] << '\n';
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