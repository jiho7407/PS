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

// 디닉 알고리즘
const ll mxN = 202; // 0~199: 공장, 200: src, 201: sink
struct Dinic{
    struct edge{
        ll to, cap, rev, flw;
    };
    vector<edge> graph[mxN];

    void clear(){
        rep(i, 0, mxN) graph[i].clear();
    }

    void addEdge(ll s, ll e, ll cap){
        graph[s].push_back({e, cap, (ll)graph[e].size(), 0});
        graph[e].push_back({s, 0, (ll)graph[s].size()-1, 0});
    }

    ll lev[mxN], work[mxN];
    bool bfs(ll src, ll sink){
        fill(lev, lev+mxN, -1);
        lev[src] = 0;
        queue<ll> q;
        q.push(src);
        while(!q.empty()){
            ll cur = q.front(); q.pop();
            for(auto &e : graph[cur]){
                if(e.cap > 0 && lev[e.to] == -1){
                    lev[e.to] = lev[cur] + 1;
                    q.push(e.to);
                }
            }
        }
        return lev[sink] != -1;
    }

    ll dfs(ll x, ll sink, ll flow){
        if(x == sink) return flow;
        for(ll &i = work[x]; i < graph[x].size(); i++){
            edge &e = graph[x][i];
            if(e.cap > 0 && lev[e.to] == lev[x] + 1){
                ll ret = dfs(e.to, sink, min(flow, e.cap));
                if(ret > 0){
                    e.cap -= ret;
                    graph[e.to][e.rev].cap += ret;
                    e.flw += ret;
                    graph[e.to][e.rev].flw -= ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    ll maxFlow(ll src, ll sink){
        ll ret = 0;
        while(bfs(src, sink)){
            fill(work, work+mxN, 0);
            while(1){
                ll flow = dfs(src, sink, 1e9);
                if(flow == 0) break;
                ret += flow;
            }
        }
        return ret;
    }
};

ll N, M;
Dinic dinic;

ll supply[mxN];

map<pii, ll> edgeIdx;
ll ans[1000];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> supply[i];

    // 공급량과 수요량이 같은지 확인
    ll pls = 0, mns = 0;
    rep(i, 0, N){
        if(supply[i] > 0) pls += supply[i];
        else mns -= supply[i];
    }
    if(pls != mns){
        cout << "-1\n";
        return;
    }

    rep(i, 0, M){
        ll u, v, s, e;
        cin >> u >> v >> s >> e;
        u--; v--;
        edgeIdx[{u, v}] = i;
        dinic.addEdge(u, v, e-s);
        supply[u] -= s;
        supply[v] += s;
        ans[i] = s;
    }
    rep(i, 0, N){
        if(supply[i] > 0) dinic.addEdge(200, i, supply[i]);
        else dinic.addEdge(i, 201, -supply[i]);
    }

    ll total = 0;
    rep(i, 0, N){
        if(supply[i] > 0) total += supply[i];
    }
    if(dinic.maxFlow(200, 201) != total){
        cout << "-1\n";
        return;
    }

    cout << "1\n";
    rep(i, 0, 202){
        for(auto &e: dinic.graph[i]){
            if(edgeIdx.find({i, e.to}) != edgeIdx.end()){
                ans[edgeIdx[{i, e.to}]] += e.flw;
            }
        }
    }
    rep(i, 0, M) cout << ans[i] << '\n';
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}