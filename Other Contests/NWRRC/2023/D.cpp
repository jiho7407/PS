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

int N;
int color[200000], par[200000];
vector<int> links[200000], coloridx[100001];

void maketree(int c, int p){
    par[c] = p;
    for(int i : links[c]){
        if(i == p) continue;
        maketree(i, c);
    }
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

int oppo(int X){
    if(X%2) return X-1;
    else return X+1;
}

bool calc(int root){
    fill(par, par+4*N, -1);
    maketree(root, -1);

    SCC.init(4*N);
    rep(i, 1, N+1){
        int a = coloridx[i][0], b = coloridx[i][1];
        SCC.add_edge(oppo(a*2), b*2); // ~a -> b
        SCC.add_edge(oppo(b*2), a*2); // ~b -> a
        SCC.add_edge(a*2, oppo(b*2)); // a -> ~b
        SCC.add_edge(b*2, oppo(a*2)); // b -> ~a
    }
    rep(i, 0, 2*N){
        if(par[i] == -1) continue;
        SCC.add_edge(i*2, par[i]*2); // a -> par[a]
        SCC.add_edge(oppo(par[i]*2), oppo(i*2)); // ~par[a] -> ~a
    }

    SCC.build();

    bool ans = true;
    rep(i, 0, 2*N){
        if(SCC.SCCID[i*2] == SCC.SCCID[i*2+1]){
            ans = false;
            break;
        }
    }

    if(ans){
        vector<int> res(4*N);
        vector<pii> points;
        rep(i, 0, 4*N) points.push_back({SCC.SCCID[i], i});
        sort(points.begin(), points.end(), greater<pii>());
        for(auto [_, i]: points){
            if(res[i] == 0){
                res[i] = 1;
                res[oppo(i)] = 2;
            }
        }
        rep(i, 0, 2*N) if(res[i*2] == 2) cout << i+1 << ' ';
        cout << '\n';
        return true;
    } 
    return false;
}

void solve(){ 
    cin >> N;
    rep(i, 0, 2*N){
        cin >> color[i];
        coloridx[color[i]].push_back(i);
    }
    rep(i, 0, 2*N-1){
        int u, v; cin >> u >> v; u--; v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    
    bool ret1, ret2;
    ret1 = calc(coloridx[1][0]);
    if(!ret1) ret2 = calc(coloridx[1][1]);
    if(!ret1 && !ret2) cout << -1 << '\n';

    rep(i, 0, 2*N) links[i].clear();
    rep(i, 1, N+1) coloridx[i].clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}