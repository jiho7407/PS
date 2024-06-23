#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 2e5+5;
int N;
vector<vector<int>> g;

struct SCC{
    int N, cnt, scnt;
    vector<int> dfsn, scc;
    vector<int> sz;
    stack<int> stk;
    void init(vector<vector<int>>& g){
        N = g.size();
        cnt = scnt=0;
        dfsn.resize(N, -1);
        scc.resize(N, -1);
        sz.resize(N, 0);
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
                sz[scnt]++;
                if(tmp==n){break;}
            }
            scnt++;
        }
        return ret;
    }
}scc;

bool visited[mxN];
ll cnt[mxN];
ll ans = 0;

ll dfs(int n){
    visited[n] = true;
    if(scc.sz[scc.scc[n]] > 1) return scc.sz[scc.scc[n]];
    if(visited[g[n][0]]) return cnt[n] = cnt[g[n][0]]+1;
    ll ret = dfs(g[n][0]);
    return cnt[n] = ret+1;
}

void solve(){
    cin >> N;
    g.resize(N);
    rep(i, 0, N){
        int x; cin >> x; x--;
        g[i].push_back(x);
    }
    scc.init(g);
    rep(i, 0, N){
        if(scc.sz[scc.scc[i]] > 1){
            visited[i] = true;
            cnt[i] = scc.sz[scc.scc[i]];
        }
    }
    rep(i, 0, N){
        if(visited[i]) continue;
        dfs(i);
    }
    rep(i, 0, N) ans += cnt[i];
    cout << ans << "\n";
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