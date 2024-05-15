#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SCC{
    int N, cnt, scnt;
    vector<int> dfsn, scc, sccv[300];
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
                sccv[scnt].push_back(tmp);
                if(tmp==n){break;}
            }
            scnt++;
        }
        return ret;
    }
};

void solve(){
    int N; cin >> N;
    vector<string> board;  
    rep(i, 0, N) {
        string s; cin >> s;
        board.push_back(s);
    }
    rep(k, 0, N) rep(i, 0, N) rep(j, 0, N){
        if(i == j || j == k || i == k) continue;
        if(board[i][j] == '1' && board[i][k] == '1' && board[k][j] == '1'){
            board[i][j] = '0';
        }
    }
    // rep(i, 0, N) cout << board[i] << "\n";
    // cout << "\n";
    vector<vector<int>> links(N);
    rep(i, 0, N){
        rep(j, 0, N){
            if(board[i][j] == '1'){
                links[i].push_back(j);
            }
        }
    }
    SCC scc(links);
    vector<pii> ans;
    rep(i, 0, scc.scnt){
        if(scc.sccv[i].size() > 1){
            rep(j, 0, scc.sccv[i].size()){
                ans.push_back({scc.sccv[i][j], scc.sccv[i][(j+1)%scc.sccv[i].size()]});
            }
        }
    }
    rep(i, 0, N) rep(j, 0, N) {
        if(scc.scc[i] != scc.scc[j] && board[i][j] == '1'){
            ans.push_back({i, j});
        }
    }

    cout << ans.size() << "\n";
    for(auto& it:ans){
        cout << it.first+1 << " " << it.second+1 << "\n";
    }
    cout << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}