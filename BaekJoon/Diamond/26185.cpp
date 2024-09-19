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
const int mxN = 600;
// 0~25: 알파벳, 26: source, 27: sink, 100~599: 단어 자리, 28: source 2
struct Dinic{
    struct edge{
        int to, cap, rev, flw;
    };
    vector<edge> graph[mxN];

    void clear(){
        rep(i, 0, mxN) graph[i].clear();
    }

    void addEdge(int s, int e, int cap){
        graph[s].push_back({e, cap, (int)graph[e].size(), 0});
        graph[e].push_back({s, 0, (int)graph[s].size()-1, 0});
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
                    e.flw += ret;
                    graph[e.to][e.rev].flw -= ret;
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

int G, L;
Dinic dinic;
int links[26][500]; // 0: 0~1, 1: 0~0, 2: 1~1
int LB[26], UB[26], supply[600];
int ans[500];

void solve(){
    fill(supply, supply+mxN, 0);
    fill(ans, ans+500, -1);
    fill(LB, LB+26, 0);
    fill(UB, UB+26, 1000);

    cin >> G >> L;
    G--;
    while(G--){
        string S, T;
        cin >> S >> T;
        rep(i, 0, 26){
            int cnt = 0;
            bool bound = false;
            rep(j, 0, L){
                if(S[j]-'a' != i) continue;
                if(T[j] == 'G'){
                    cnt++;
                    links[i][j] = 2;
                }
                else if(T[j] == 'Y'){
                    cnt++;
                    links[i][j] = 1;
                }
                else{
                    bound = true;
                    links[i][j] = 1;
                }
            }
            LB[i] = max(LB[i], cnt);
            if(bound) UB[i] = min(UB[i], cnt);
        }
    }
    
    supply[28] = L;
    rep(i, 0, L) supply[100+i] = -1;
    rep(i, 0, 26){
        dinic.addEdge(28, i, UB[i]-LB[i]);
        supply[i] += LB[i];
        supply[28] -= LB[i];
    }
    
    rep(i, 0, 26) rep(j, 0, L){
        if(links[i][j] == 1) continue;
        else if(links[i][j] == 0){
            dinic.addEdge(i, 100+j, 1);
        }else{
            dinic.addEdge(i, 100+j, 1);
            supply[i]--;
            supply[100+j]++;
            ans[j] = i;
        }
    }
    rep(i, 0, 600){
        if(supply[i] > 0) dinic.addEdge(26, i, supply[i]);
        else if(supply[i] < 0) dinic.addEdge(i, 27, -supply[i]);
    }
    dinic.addEdge(27, 26, 1e9);
    dinic.maxFlow(26, 27);

    rep(i, 0, 26){
        for(auto &e: dinic.graph[i]){
            if(e.flw <= 0) continue;
            if(e.flw == 1){
                ans[e.to-100] = i;
            }
        }
    }

    rep(i, 0, L){
        cout << (char)(ans[i]+'a');
    }
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