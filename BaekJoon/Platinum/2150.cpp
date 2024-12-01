#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SCC{
    int N;
    vector<vector<int>> gph;
    vector<int> par, SCCID;
    vector<bool> finished;
    stack<int> stk;
    int idx, SCCidx;

    void init(int n){
        N = n;
        gph.clear(); gph.resize(n);
        par.clear(); par.resize(n, -1);
        SCCID.clear(); SCCID.resize(n, -1);
        finished.clear(); finished.resize(n);
        while(!stk.empty()) stk.pop();
        idx = SCCidx = 0;
    }

    void add_edge(int u, int v){
        gph[u].push_back(v);
    }

    int dfs(int x){
        par[x] = idx++;
        stk.push(x);

        int ret = par[x];
        for(auto nxt: gph[x]){
            if(finished[nxt]) continue;
            if(par[nxt] == -1) ret = min(ret, dfs(nxt));
            else ret = min(ret, par[nxt]);
        }

        if(ret == par[x]){
            while(1){
                int top = stk.top();
                stk.pop();
                finished[top] = true;
                SCCID[top] = SCCidx;
                if(top == x) break;
            }
            SCCidx++;
        }

        return ret;
    }

    void build(){
        rep(i, 0, N) if(par[i] == -1) dfs(i);
    }
}SCC;

void solve(){ 
    int V, E; cin >> V >> E;
    SCC.init(V);
    rep(i, 0, E){
        int u, v; cin >> u >> v; u--; v--;
        SCC.add_edge(u, v);
    }
    SCC.build();
    vector<vector<int>> SCCs(SCC.SCCidx);
    rep(i, 0, V) SCCs[SCC.SCCID[i]].push_back(i);
    rep(i, 0, SCC.SCCidx){
        sort(SCCs[i].begin(), SCCs[i].end());
    }
    sort(SCCs.begin(), SCCs.end());
    cout << SCC.SCCidx << '\n';
    for(auto& SCC: SCCs){
        for(auto& v: SCC) cout << v+1 << ' ';
        cout << "-1\n";
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}