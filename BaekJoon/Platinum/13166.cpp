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

// 이분 매칭
// 호프크로프트 카프 알고리즘 사용
// 시간 복잡도 O(Esqrt(V))

const int MAXN = 200000, MAXM = 400000; // 0-based로 사용. 그렇지 않을시 match(N+1) 조심하기.
struct BipartiteMatching{
    vector<pii> graph[MAXN];
    int dis[MAXN], L[MAXN], R[MAXM], vis[MAXN];
    void clear(){ rep(i, 0, MAXN) graph[i].clear(); }
    void addEdge(int l, int r, int c){ graph[l].push_back({r, c}); }

    bool bfs(int n, int cost){
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
            for(auto [r, c] : graph[l]){
                if(c > cost) continue;
                if(R[r] == -1) ok = 1;
                else if(!dis[R[r]]){
                    dis[R[r]] = dis[l] + 1;
                    q.push(R[r]);
                }
            }
        }
        return ok;
    }

    bool dfs(int l, int cost){
        if(vis[l]) return 0;
        vis[l] = 1;
        for(auto [r, c] : graph[l]){
            if(c > cost) continue;
            if(R[r] == -1 || (!vis[R[r]] && dis[R[r]] == dis[l] + 1 && dfs(R[r], cost))){
                L[l] = r;
                R[r] = l;
                return true;
            }
        }
        return 0;
    }

    int match(int n, int cost){
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        int ret = 0;
        while(bfs(n, cost)){
            memset(vis, 0, sizeof(vis));
            rep(i, 0, n){
                if(L[i] == -1 && dfs(i, cost)) ret++;
            }
        }
        return ret;
    }
}Bpm;

void solve(){
    int N; cin >> N;
    rep(i, 0, N){
        int a, ka, b, kb; cin >> a >> ka >> b >> kb;
        a--; b--;
        Bpm.addEdge(i, a, ka);
        Bpm.addEdge(i, b, kb);
    }
    int INF = int(1e6)+1;
    int ok = INF, ng=-1;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        if(Bpm.match(N, mid) == N) ok = mid;
        else ng = mid;
    }
    if (ok == INF) cout << -1;
    else cout << ok;
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