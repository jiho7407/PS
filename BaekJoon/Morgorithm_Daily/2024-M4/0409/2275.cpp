
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, H, root;
vector<pii> links[10000];
int mx[10000];

void dfs(int cur, int par){
    for(auto [goal, cost] : links[cur]){
        if(goal == par) continue;
        dfs(goal, cur);
        mx[cur] = max(mx[cur], mx[goal] + cost);
    }
}

int dfs2(int cur, int par, int curcost){
    int ret = 0;
    for(auto [goal, cost] : links[cur]){
        if(goal == par) continue;
        int nxtcost = mx[goal] + cost + curcost;
        if(nxtcost <= H) continue;
        int cut = min(cost, nxtcost - H);
        ret += cut;
        ret += dfs2(goal, cur, curcost + cost -cut);
    }
    return ret;
}

void solve(){
    cin >> N >> H;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        if(a == 0){root = i; continue;}
        links[a-1].push_back({i,b});
        links[i].push_back({a-1,b});
    }
    fill(mx, mx+N, 0);
    dfs(root, -1);
    int ans = 0;
    cout << dfs2(root, -1, 0) << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}