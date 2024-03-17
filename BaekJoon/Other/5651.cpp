#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 310, INF = 2147483647;
int TC, N, M;
int cap[mxN][mxN], flow[mxN][mxN];
int lev[mxN];
int work[mxN];
vector<int> links[mxN];
int linkcnt[mxN][mxN];

bool bfs(int S, int E){
    fill(lev, lev+N, -1);
    lev[S] = 0;

    queue<int> Q; Q.push(S);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto goal: links[cur]){
            if(lev[goal] == -1 && cap[cur][goal]-flow[cur][goal]>0){
                lev[goal] = lev[cur]+1;
                Q.push(goal);
            }
        }
    }
    if(lev[E] == -1) return false;
    else return true;
}

// 디닉 알고리즘
int dfs(int cur, int goal, int f){
    if(cur == goal) return f;

    for(int &i = work[cur]; i<links[cur].size(); i++){
        int next = links[cur][i];
        int posf = cap[cur][next]-flow[cur][next];
        if(lev[next] == lev[cur]+1 && posf>0){
            int tempf = dfs(next, goal, min(f, posf));
            if(tempf>0){
                flow[cur][next] += tempf;
                flow[next][cur] -= tempf;
                return tempf;
            }
        }
    }
    return 0;
}

int main(){
    fastio();

    cin >> TC;
    while(TC--){
        // 입력받기
        cin >> N >> M;
        for(int i = 0; i<N; i++){
            fill(cap[i], cap[i]+N, 0);
            fill(flow[i], flow[i]+N, 0);
            fill(linkcnt[i], linkcnt[i]+N, 0);
            links[i].clear();
        }
        int f, t, b;
        while(M--){
            cin >> f >> t >> b;
            cap[f-1][t-1] += b;
            linkcnt[f-1][t-1]++;
            links[f-1].push_back(t-1);
            links[t-1].push_back(f-1);
        }

        // 최대유량 찾기
        int MF = 0;
        while(bfs(0, N-1)){
            fill(work, work+N, 0);
            while(true){
                f = dfs(0, N-1, INF);
                if(f==0) break;
                MF += f;
            }
        }

        // 각 포화간선에서 줄여보면서 테스트
        int ans = 0;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(cap[i][j] == 0 || cap[i][j] != flow[i][j]) continue;
                cap[i][j]--;
                if(!bfs(i, j)) ans += linkcnt[i][j];
                cap[i][j]++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}