#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<int> links[100000];
ll C[100000], nodes[100000];
ll start = 0, ans = 1e15;

void dfs(int cur, int parent, int lev){
    nodes[cur] = C[cur];
    start += C[cur]*lev;
    for(auto goal: links[cur]){
        if(goal == parent) continue;
        dfs(goal, cur, lev+1);
        nodes[cur] += nodes[goal];
    }
}

void dfs2(ll curcost, int cur, int parent){
    ans = min(ans, curcost);
    for(auto goal: links[cur]){
        if(goal == parent) continue;
        dfs2(curcost + nodes[0] - 2*nodes[goal], goal, cur);
    }
}

void solve(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    dfs(0, -1, 0);
    ans = start;
    dfs2(start, 0, -1);
    cout << ans << "\n";
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}