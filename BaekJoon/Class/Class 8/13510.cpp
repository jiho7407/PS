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

// Segment Tree
struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return max(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }

    int query(int L, int R){
        // cout << "query: " << L << ' ' << R << endl;
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

const int mxN = 1e5;
int N, Q;
vector<pii> links[mxN];
vector<tuple<int, int, int>> edges;

int sz[mxN], dep[mxN], par[mxN], top[mxN], in[mxN], out[mxN];
vector<int> child[mxN];
/*
sz: 서브트리 크기
dep: 깊이, par: 부모, top: 체인의 루트
in: dfs 순서, out: dfs 역순서
child: 자식들
*/

void dfs1(int c, int p){
    for(auto [n, w]: links[c]){
        if(n == p) continue;
        child[c].push_back(n);
        dfs1(n, c);
    }
}

void dfs2(int c, int p){
    sz[c] = 1;
    for(auto &n: child[c]){
        dep[n] = dep[c] + 1;
        par[n] = c;
        dfs2(n, c);
        sz[c] += sz[n];
        if(sz[n] > sz[child[c][0]]) swap(n, child[c][0]);
    }
}

int idx = 0;
void dfs3(int c, int p){
    in[c] = idx++;
    for(auto n: child[c]){
        if(n == child[c][0]) top[n] = top[c];
        else top[n] = n;
        dfs3(n, c);
    }
    out[c] = idx;
}

int query(int a, int b){
    int ans = 0;
    while(top[a] != top[b]){
        if(dep[top[a]] > dep[top[b]]) swap(a, b);
        ans = max(ans, ST.query(in[top[b]], in[b]));
        b = par[top[b]];
    }

    if(a == b) return ans;
    if(dep[a] > dep[b]) swap(a, b);
    ans = max(ans, ST.query(in[a]+1, in[b]));
    return ans;
}


void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        links[u].push_back({v, w});
        links[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    // HLD 전처리
    ST.init(N);
    dfs1(0, -1);
    dfs2(0, -1);
    dfs3(0, -1);

    for(auto [u, v, w]: edges){
        if(dep[u] > dep[v]) swap(u, v);
        ST.set(in[v], w);
    }
    ST.build();

    // rep(i, 0, N) cout << in[i] << ' ';
    // cout << '\n';

    // rep(i, 0, N){
    //     cout << in[i] << ' ' << child[in[i]].size() << '\n';
    //     for(auto n: child[in[i]]) cout << n << ' ';
    //     cout << '\n';
    // }

    cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int i, c; cin >> i >> c; i--;
            auto [u, v, w] = edges[i];
            if(dep[u] > dep[v]) swap(u, v);
            ST.update(in[v], c);
        }
        else{
            int u, v; cin >> u >> v; u--, v--;
            cout << query(u, v) << '\n';
        }
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