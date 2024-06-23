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

int Q;  
vector<pair<char, int>> query;
int treecnt = 0;
int treeidx[100000];

struct Tree{
    int N = 0;
    vector<vector<int>> links;
    vector<int> depth;
    vector<vector<int>> parent;
    map<int, int> idx;
    int rada = -1, radb = -1;

    int getidx(int a){
        if(idx.count(a)) return idx[a];
        return idx[a] = N++;
    }

    Tree(int a){
        links.resize(1);
        idx[a] = N++;
    }

    void addEdge(int u, int v){
        // cout << "addEdge\n" << u << ' ' << v << endl;
        u = getidx(u);
        v = getidx(v);
        // cout << u << ' ' << v << endl;
        if(links.size() <= max(u, v)) links.resize(max(u, v)+1);
        links[u].push_back(v);
        links[v].push_back(u);
    }

    void build(){
        parent = vector<vector<int>>(N, vector<int>(20, -1));
        depth = vector<int>(N, 0);
        maketree(0, -1);
        makeLCA();
    }

    void maketree(int cur, int par){
        for(auto nxt: links[cur]){
            if(nxt == par) continue;
            depth[nxt] = depth[cur] + 1;
            parent[nxt][0] = cur;
            maketree(nxt, cur);
        }
    }

    void makeLCA(){
        rep(j, 1, 20) rep(i, 0, N){
            if(parent[i][j-1] == -1) continue;
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    int getLCA(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        rep(i, 0, 20) if(diff & (1<<i)) u = parent[u][i];
        if(u == v) return u;
        for(int i = 19; i >= 0; i--){
            if(parent[u][i] != parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }
    
    int getDist(int u, int v){
        return depth[u] + depth[v] - 2*depth[getLCA(u, v)];
    }

    void update(int a){
        // cout << "update " << a << endl;
        a = getidx(a);
        // cout << rada << ' ' << radb << endl;
        if(rada == -1) rada = a;
        else if(radb == -1) radb = a;
        else{
            if(getDist(a, rada) > getDist(rada, radb)) radb = a;
            else if(getDist(a, radb) > getDist(rada, radb)) rada = a;
        }
        // cout << rada << ' ' << radb << endl;
    }

    void query(int a){
        // cout << "query\n";
        a = getidx(a);
        if(radb == -1) cout << 0 << '\n';
        else cout << max(getDist(a, rada), getDist(a, radb)) << '\n';
    }
};

vector<Tree> trees;

void solve(){
    cin >> Q;
    rep(i, 0, Q){
        char op; int x;
        cin >> op >> x;
        query.push_back({op, x-1});
    }
    
    int N = 0;
    for(auto [op, x]: query){
        if(op == 'Q') continue;
        if(x == -2){
            trees.push_back(Tree(N));
            treeidx[N] = treecnt++;
        }else{
            treeidx[N] = treeidx[x];
            trees[treeidx[x]].addEdge(x, N);
        }
        N++;
    }
    rep(i, 0, treecnt) trees[i].build();
    // rep(i, 0, N) cout << treeidx[i] << ' ';
    // cout << treecnt << '\n';
    // rep(i, 0, treecnt){
    //     cout << trees[i].N << '\n';
    //     for(auto [k, v]: trees[i].idx){
    //         cout << k << ' ' << v << '\n';
    //     }
    //     for(auto nxt: trees[i].links){
    //         for(auto v: nxt){
    //             cout << v << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }
    // cout << endl;
    int M = 0;
    for(auto [op, x]: query){
        if(op == 'Q'){
            trees[treeidx[x]].query(x);
        }
        else{
            trees[treeidx[M]].update(M);
            M++;
        }
        // cout << "end" << endl;
    }
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