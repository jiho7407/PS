#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int V, E;
vector<int> links[100010];
int visitidx;
int visited[100010];
vector<pair<int, int>> Bridge;

int dfs(int cur, int par){
    visited[cur] = visitidx++;
    int curnum = visited[cur];
    for(auto goal: links[cur]){
        if(goal == par) continue;
        if(visited[goal] != -1) curnum = min(curnum, visited[goal]);
        else{
            int nxtnum = dfs(goal, cur);
            if(nxtnum > visited[cur]) Bridge.push_back({min(cur, goal), max(cur, goal)});
            curnum = min(curnum, nxtnum);
        }
    }
    return curnum;
}

int main() {
    cin >> V >> E;
    for(int i = 0; i<E; i++){
        int s, e;
        cin >> s >> e;
        links[s].push_back(e);
        links[e].push_back(s);
    }
    visitidx = 0;
    fill(visited, visited+V+1, -1);
    for(int i = 1; i<=V; i++){
        if(visited[i] == -1) dfs(i, 0);
    }
    cout << Bridge.size() << "\n";
    sort(Bridge.begin(), Bridge.end());
    for(pair<int, int> p: Bridge) cout << p.first << " " << p.second << "\n";
}