/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 2502;
struct Dinic{
    struct edge{
        int to, cap, rev;
    };
    vector<edge> graph[mxN];

    void clear(){
        rep(i, 0, mxN) graph[i].clear();
    }

    void addEdge(int s, int e, int cap){
        graph[s].push_back({e, cap, (int)graph[e].size()});
        graph[e].push_back({s, 0, (int)graph[s].size()-1});
    }

    int lev[mxN], work[mxN];
    bool bfs(int src, int sink){
        fill(lev, lev+mxN, -1);
        lev[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto &e : graph[cur]){
                if(e.cap > 0 && lev[e.to] == -1){
                    lev[e.to] = lev[cur] + 1;
                    q.push(e.to);
                }
            }
        }
        return lev[sink] != -1;
    }

    int dfs(int x, int sink, int flow){
        if(x == sink) return flow;
        for(int &i = work[x]; i < graph[x].size(); i++){
            edge &e = graph[x][i];
            if(e.cap > 0 && lev[e.to] == lev[x] + 1){
                int ret = dfs(e.to, sink, min(flow, e.cap));
                if(ret > 0){
                    e.cap -= ret;
                    graph[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    int maxFlow(int src, int sink){
        int ret = 0;
        while(bfs(src, sink)){
            fill(work, work+mxN, 0);
            while(1){
                int flow = dfs(src, sink, 1e9);
                if(flow == 0) break;
                ret += flow;
            }
        }
        return ret;
    }
};

int N, M;
int board[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
Dinic dinic;

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    int tot = 0;
    dinic.clear();
    int src = N*M, sink = N*M + 1;
    rep(i, 0, N) rep(j, 0, M){
        tot += board[i][j];
        if((i+j)%2 == 0) dinic.addEdge(src, i*M+j, board[i][j]);
        else dinic.addEdge(i*M+j, sink, board[i][j]);
        rep(d, 0, 4){
            int nx = i + dx[d], ny = j + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            int nxt = nx * M + ny;
            if((i+j)%2 == 0) dinic.addEdge(i*M+j, nxt, 1e9);
            else dinic.addEdge(nxt, i*M+j, 1e9);
        }
    }
    cout << tot - dinic.maxFlow(src, sink) << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}