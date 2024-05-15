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


void solve(){
    int N, M; cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i, 0, M){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
    }
    SCC scc(g);
    int inlink[scc.scnt];
    fill(inlink, inlink+scc.scnt, 0);
    for(int i = 0; i<N; i++){
        for(auto& it:g[i]){
            if(scc.scc[i] != scc.scc[it]){
                inlink[scc.scc[it]]++;
            }
        }
    }
    int T; cin >> T;
    set<int> TC;
    rep(i, 0, T){
        int a; cin >> a; a--;
        TC.insert(scc.scc[a]);
    }
    int ans = 0;
    rep(i, 0, scc.scnt){
        if(inlink[i] == 0){
            if(TC.find(i) != TC.end()){
                ans++;
            }
            else{
                cout << -1;
                return;
            }
        }
    }
    cout << ans;
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