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

const int S = 500, T = 501, INF = 1e9;
int N, camp[500];
int cap[502][502], flow[502][502];
vector<int> links[502];
int dfsvisit[502];
int lev[502];

bool bfs(int src, int sink){
    fill_n(lev, 502, -1);
    fill_n(dfsvisit, 502, 0);
    queue<int> q;
    q.push(src);
    lev[src] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt: links[cur]){
            if(lev[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0){
                lev[nxt] = lev[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return lev[sink] != -1;
}

int dfs(int cur, int sink, int f){
    if(cur == sink) return f;
    for(int &i = dfsvisit[cur]; i < links[cur].size(); i++){
        int nxt = links[cur][i];
        if(lev[nxt] == lev[cur] + 1 && cap[cur][nxt] - flow[cur][nxt] > 0){
            int df = dfs(nxt, sink, min(f, cap[cur][nxt] - flow[cur][nxt]));
            if(df > 0){
                flow[cur][nxt] += df;
                flow[nxt][cur] -= df;
                return df;
            }
        }
    }
    return 0;
}

int match(int src, int sink){
    int ret = 0;
    while(bfs(src, sink)){
        while(1){
            int f = dfs(src, sink, INF);
            if(f == 0) break;
            ret += f;
        }
    }
    return ret;
}

void solve(){
    cin >> N;
    fill_n(&cap[0][0], 502*502, 0);
    fill_n(&flow[0][0], 502*502, 0);
    rep(i, 0, N) cin >> camp[i];
    rep(i, 0, N) rep(j, 0, N){
        cin >> cap[i][j];
        if(i != j) links[i].push_back(j);
    }
    rep(i, 0, N){
        if(camp[i] == 0) continue;
        else if(camp[i] == 1){
            cap[S][i] = INF;
            links[S].push_back(i);
            links[i].push_back(S);
        }
        else if(camp[i] == 2){
            cap[i][T] = INF;
            links[i].push_back(T);
            links[T].push_back(i);
        }
    }
    cout << match(S, T) << '\n';

    bool isA[502];
    fill_n(isA, 502, false);
    queue<int> q;
    q.push(S);
    isA[S] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt: links[cur]){
            if(!isA[nxt] && cap[cur][nxt] - flow[cur][nxt] > 0){
                isA[nxt] = true;
                q.push(nxt);
            }
        }
    }
    rep(i, 0, N){
        if(isA[i]) cout << i+1 << ' ';
    }
    cout << '\n';
    rep(i, 0, N){
        if(!isA[i]) cout << i+1 << ' ';
    }
    cout << '\n';
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