// 유파
// 분리집합
struct UnionFind{
    int par[1000], cnt[1000];
    int group;

    void init(int N){
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
    }
}UF;

// 방향그래프 사이클 판별
struct Graph{
    int V;
    vector<vector<int>> gph;
    vector<int> visited;
    // 0: 방문하지 않은 노드
    // 1: 방문했으나 dfs가 끝나지 않은 노드
    // 2: 방문했고 dfs가 끝난 노드

    Graph(int V): V(V){
        gph.resize(V);
        visited.resize(V);
    }

    void add_edge(int u, int v){
        gph[u].push_back(v);
    }

    bool dfs_cycle(int cur){
        if(visited[cur] == 1) return true;
        if(visited[cur] == 2) return false;

        visited[cur] = 1;
        for(auto nxt: gph[cur]){
            if(dfs_cycle(nxt)) return true;
        }
        visited[cur] = 2;
        return false;
    }
};