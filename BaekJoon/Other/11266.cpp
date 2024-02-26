#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int V, E;
vector<vector<int>> links;
int visitidx;
int visited[10010];
bool ATP[10010];

int dfs(int a, bool root){
    visited[a] = visitidx++;
    int curnum = visited[a];
    int degree = 0;
    for(auto goal: links[a]){
        if(visited[goal] != -1) curnum = min(curnum, visited[goal]);
        else{
            degree++;
            int subnum = dfs(goal, false);
            if(!root && subnum >= visited[a]) ATP[a] = true;
            curnum = min(curnum, subnum);
        }
    }

    if(root && degree>=2) ATP[a] = true;
    return curnum;
}

int main(){
    cin >> V >> E;
    links.resize(V+1);
    for(int i = 0; i<E; i++){
        int s, e;
        cin >> s >> e;
        links[s].push_back(e);
        links[e].push_back(s);
    }
    visitidx = 0;
    fill(visited, visited+V+1, -1);
    fill(ATP, ATP+V+1, false);
    for(int i = 1; i<=V; i++){
        if(visited[i] == -1) dfs(i, true);
    }
    int ans=0;
    vector<int> anslst;
    for(int i = 1; i<=V; i++){
        if(ATP[i]){
            ans++;
            anslst.push_back(i);
        }
    }
    cout << ans << "\n";
    for(auto p: anslst) cout << p << " ";
}