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

const int mxN = 200;
int N, M;

vector<int> edge[mxN];
int cap[mxN][mxN], flw[mxN][mxN];
int lev[mxN], work[mxN];

// 디닉 알고리즘
bool bfs(){
    fill(lev, lev+N, -1);
    fill(work, work+N, 0);
    lev[0] = 0;

    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt: edge[cur]){
            if(lev[nxt] == -1 && cap[cur][nxt] > flw[cur][nxt]){
                lev[nxt] = lev[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return lev[N-1] != -1;
}

int dfs(int cur, int flow){
    if(cur == N-1) return flow;

    for(int &i = work[cur]; i < edge[cur].size(); i++){
        int nxt = edge[cur][i];
        if(lev[nxt] == lev[cur] + 1 && cap[cur][nxt] > flw[cur][nxt]){
            int ret = dfs(nxt, min(flow, cap[cur][nxt] - flw[cur][nxt]));
            if(ret > 0){
                flw[cur][nxt] += ret;
                flw[nxt][cur] -= ret;
                return ret;
            }
        }
    }
    return 0;
}

void solve(){
    // 입력
    cin >> N >> M;
    rep(i, 0, M){
        int u, v; cin >> u >> v; u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
        if(u == 0 || v == N-1) cap[u][v] = 1;
        else cap[u][v] = 1e4;
    }

    // 디닉 알고리즘
    int ans = 0;
    while(bfs()){
        while(1){
            int flow = dfs(0, 1e9);
            if(flow == 0) break;
            ans += flow;
        }
    }

    cout << ans << '\n';


    // 초기화
    rep(i, 0, N){
        edge[i].clear();
        fill(cap[i], cap[i]+N, 0);
        fill(flw[i], flw[i]+N, 0);
    }
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