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