#include <bits/stdc++.h>
using namespace std;

int cap[400][400], flow[400][400];
vector<int> links[400];
int N, K, D;

void init(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> N >> K >> D;
    for(int i = N+2; i<N+2+D; i++){
        int d;
        cin >> d;
        links[i].push_back(1);
        links[1].push_back(i);
        cap[i][1]=d;
    }

    for(int i = 2; i<N+2; i++){
        int n;
        cin >> n;
        links[0].push_back(i);
        links[i].push_back(0);
        cap[0][i] = K;
        for(int j = 0; j<n; j++){
            int e;
            cin >> e;
            links[i].push_back(N+1+e);
            links[N+1+e].push_back(i);
            cap[i][N+1+e] = 1;
        }
    }
}

int solve(int S, int E){
    int ans=0;

    while(true){
        vector<int> prev(400, -1);
        queue<int> Q;
        Q.push(S);
        prev[S] = S;
        while(!Q.empty() && prev[E] == -1){
            int cur = Q.front(); Q.pop();
            for(auto goal: links[cur]){
                if(cap[cur][goal]-flow[cur][goal] > 0 && prev[goal] == -1){
                    Q.push(goal);
                    prev[goal] = cur;
                }
            }
        }
        if(prev[E] == -1) break;

        int curflow = 123456789;
        for(int i=E; i!=S; i=prev[i]){
            curflow = min(curflow, cap[prev[i]][i] - flow[prev[i]][i]);
        }
        for(int i=E; i!=S; i=prev[i]){
            flow[prev[i]][i] += curflow;
            flow[i][prev[i]] -= curflow;
        }
        ans += curflow;
    }
    return ans;
}

int main(){
    init();
    input();
    cout << solve(0, 1);
}