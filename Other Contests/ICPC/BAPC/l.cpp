#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct SCC{
    int N, cnt, scnt;
    vector<int> dfsn, scc;
    stack<int> stk;
    SCC(vector<vector<int>>& g){
        N = g.size();
        cnt = scnt=0;
        dfsn.resize(N, -1);
        scc.resize(N, -1);
        for(int i = 0; i<N; i++){
            if(dfsn[i] == -1){dfs(g, i);}
        }
    }
    int dfs(vector<vector<int>>& g, int n){
        dfsn[n]=cnt; ++cnt; stk.push(n);
        int ret = dfsn[n];
        for(auto& it:g[n]){
            if (dfsn[it] == -1){ret=min(ret, dfs(g, it));}
            else{
                if (scc[it]==-1){ret=min(ret, dfsn[it]);}
            }
        }
        if(ret==dfsn[n]){
            while(!stk.empty()){
                int tmp = stk.top(); stk.pop();
                scc[tmp]=scnt;
                if(tmp==n){break;}
            }
            scnt++;
        }
        return ret;
    }
};

int QN, QM;
vector<vector<int>> links;
vector<pair<int, int>> lines;

void solve(){
    cin >> QN >> QM;
    links.resize(QN, vector<int>(0, 0));
    for(int i = 0; i<QM; i++){
        int s, e;
        cin >> s >> e;
        links[s-1].push_back(e-1);
        lines.push_back({s-1, e-1});
    }
    SCC scc = SCC(links);
    int inlink[scc.scnt];
    fill(inlink, inlink+scc.scnt, 0);s
    for(int i = 0; i<QM; i++){
        if(scc.scc[lines[i].first] == scc.scc[lines[i].second]) continue;
        inlink[scc.scc[lines[i].second]]++;
    }
    // for(int i = 0; i<QN; i++) cout << scc.scc[i] << " ";
    // cout << "\n";
    int ans = 0;
    for(int i = 0; i<scc.scnt; i++){
        if(inlink[i] == 0) ans++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}