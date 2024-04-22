#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<int> child[60];
int cmd;
int ans;

void dfs(int cur){
    if(child[cur].empty()){
        cout << cur << " ";
        ans++;
        return;
    }
    for(auto goal: child[cur]){
        if(goal==cmd) continue;
        dfs(goal);
    }
    return;
}

int main(){
    fastio();
    cin >> N;
    int p, root;
    for(int i = 0; i<N; i++){
        cin >> p;
        if(p == -1) root = i;
        child[p].push_back(i);
    }
    ans = 0;
    dfs(root);
    cin >> cmd;
    cout << ans;
}