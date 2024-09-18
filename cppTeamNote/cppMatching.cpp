// 이분 매칭
// 호프크로프트 카프 알고리즘 사용
// 시간 복잡도 O(Esqrt(V))

const int MAXN = 1000, MAXM = 1000; // 0-based로 사용. 그렇지 않을시 match(N+1) 조심하기.
struct BipartiteMatching{
    vector<int> graph[MAXN];
    int dis[MAXN], L[MAXN], R[MAXM], vis[MAXN];
    void clear(){ rep(i, 0, MAXN) graph[i].clear(); }
    void addEdge(int l, int r){ graph[l].push_back(r); }

    bool bfs(int n){
        queue<int> q;
        bool ok = 0;
        memset(dis, 0, sizeof(dis));
        for(int i = 0; i < n; i++){
            if(L[i] == -1){
                q.push(i);
                dis[i] = 1;
            }
        }
        while(!q.empty()){
            int l = q.front(); q.pop();
            for(auto &r : graph[l]){
                if(R[r] == -1) ok = 1;
                else if(!dis[R[r]]){
                    dis[R[r]] = dis[l] + 1;
                    q.push(R[r]);
                }
            }
        }
        return ok;
    }

    bool dfs(int l){
        if(vis[l]) return 0;
        vis[l] = 1;
        for(auto &r : graph[l]){
            if(R[r] == -1 || (!vis[R[r]] && dis[R[r]] == dis[l] + 1 && dfs(R[r]))){
                L[l] = r;
                R[r] = l;
                return true;
            }
        }
        return 0;
    }

    int match(int n){
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        int ret = 0;
        while(bfs(n)){
            memset(vis, 0, sizeof(vis));
            rep(i, 0, n){
                if(L[i] == -1 && dfs(i)) ret++;
            }
        }
        return ret;
    }
}Bpm;


// 디닉 알고리즘
const int mxN = 302;
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

// 최소비용 최대유량
// MCMF
struct MCMF{
    struct Edge{
        int to, cap, cost, inv;
    };

    vector<Edge> edge[mxN];
    int S, T;

    void clear(){
        rep(i, 0, mxN) edge[i].clear();
    }

    void add(int s, int e, int cap, int cost){
        edge[s].push_back({e, cap, cost, (int)edge[e].size()});
        edge[e].push_back({s, 0, -cost, (int)edge[s].size()-1});
    }

    void setST(int s, int t){
        S = s, T = t;
    }

    int dist[mxN], pa[mxN], pe[mxN]; 
    bool inQ[mxN];

    bool spfa(){
        fill(dist, dist+mxN, 1e9);
        fill(inQ, inQ+mxN, 0);

        queue<int> q;
        q.push(S);
        dist[S] = 0;
        inQ[S] = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(int i=0; i<edge[cur].size(); i++){
                auto [nxt, cap, cost, inv] = edge[cur][i];
                if(cap>0 && dist[nxt]>dist[cur]+cost){
                    dist[nxt] = dist[cur]+cost;
                    pa[nxt] = cur;
                    pe[nxt] = i;
                    if(!inQ[nxt]){
                        q.push(nxt);
                        inQ[nxt] = 1;
                    }
                }
            }
        }
        return dist[T] != 1e9;
    }

    int match(){
        int ret = 0;
        while(spfa()){
            int cap = 1e9;
            for(int i=T; i!=S; i=pa[i]){
                cap = min(cap, edge[pa[i]][pe[i]].cap);
            }
            ret += dist[T]*cap;
            for(int i=T; i!=S; i=pa[i]){
                int inv = pe[i];
                edge[pa[i]][inv].cap -= cap;
                edge[i][edge[pa[i]][inv].inv].cap += cap;
            }
        }
        return ret;
    }
}MCMF;

// 최소비용 최대유량
// cost가 실수일때
struct MCMF{
    struct Edge{
        int to, cap, inv;
        double cost;

        Edge(int to, int cap, int inv, double cost):to(to), cap(cap), inv(inv), cost(cost){}
    };

    vector<Edge> edge[mxN];
    int S, T;

    void clear(){
        rep(i, 0, mxN) edge[i].clear();
    }

    void add(int s, int e, int cap, double cost){
        edge[s].push_back(Edge(e, cap, edge[e].size(), cost));
        edge[e].push_back(Edge(s, 0, edge[s].size()-1, -cost));
    }

    void setST(int s, int t){
        S = s, T = t;
    }

    double dist[mxN];
    int pa[mxN], pe[mxN]; 
    bool inQ[mxN];

    bool spfa(){
        fill(dist, dist+mxN, 1e9);
        fill(inQ, inQ+mxN, 0);

        queue<int> q;
        q.push(S);
        dist[S] = 0;
        inQ[S] = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(int i=0; i<edge[cur].size(); i++){
                int nxt = edge[cur][i].to;
                int cap = edge[cur][i].cap;
                double cost = edge[cur][i].cost;
                if(cap>0 && dist[nxt]>dist[cur]+cost + 1e-9){ // 실수오차 조심
                    dist[nxt] = dist[cur]+cost;
                    pa[nxt] = cur;
                    pe[nxt] = i;
                    if(!inQ[nxt]){
                        q.push(nxt);
                        inQ[nxt] = 1;
                    }
                }
            }
        }
        return dist[T] != 1e9;
    }

    double match(){
        double ret = 0;
        rep(i, 0, N){
            spfa();
            ret += dist[T];
            for(int j=T; j!=S; j=pa[j]){
                int inv = pe[j];
                edge[pa[j]][inv].cap--;
                edge[j][edge[pa[j]][inv].inv].cap++;
            }
        }
        return ret;
    }
}MCMF;