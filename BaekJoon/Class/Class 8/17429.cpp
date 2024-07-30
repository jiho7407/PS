#include <bits/stdc++.h>
#define ll unsigned int
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

// Lazy Segment Tree, Lazy Propagation
// 구간 업데이트, 구간 쿼리

struct LazySegmentTree{
    vector<ll> tree;
    vector<pll> lazy;
    ll sz;

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, 0);
        lazy.assign(sz<<1, {1, 0});
    }

    void pull(ll node){
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void push(ll node, ll start, ll end){
        if(lazy[node].first == 1 && lazy[node].second == 0) return;
        tree[node] = lazy[node].first * tree[node] + (end-start+1) * lazy[node].second;
        if(start != end){
            lazy[node<<1].first *= lazy[node].first;
            lazy[node<<1].second = lazy[node<<1].second * lazy[node].first + lazy[node].second;
            lazy[node<<1|1].first *= lazy[node].first;
            lazy[node<<1|1].second = lazy[node<<1|1].second * lazy[node].first + lazy[node].second;
        }
        lazy[node] = {1, 0};
    }

    void set(ll idx, ll val){ tree[sz|idx] = val; }
    void build(){ for(ll i = sz-1; i > 0; i--) pull(i); }
    
    void update(ll left, ll right, pll diff){
        update(1, 0, sz-1, left, right, diff);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, pll diff){
        push(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node].first = diff.first;
            lazy[node].second = diff.second;
            push(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        pull(node);
        return;
    }

    ll query(ll left, ll right){
        return query(1, 0, sz-1, left, right);
    }

    ll query(ll node, ll start, ll end, ll left, ll right){
        push(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        ll mid = (start + end)>>1;
        ll lq = query(node<<1, start, mid, left, right);
        ll rq = query(node<<1|1, mid+1, end, left, right);
        return lq + rq;
    }
};

const int mxN = 5e5;
LazySegmentTree LST(mxN);
int N, Q;

vector<int> links[mxN], child[mxN];
int sz[mxN], dep[mxN], par[mxN], top[mxN], in[mxN], out[mxN];

void maketree(int c, int p){
    for(auto &n: links[c]){
        if(n == p) continue;
        child[c].push_back(n);
        maketree(n, c);
    }
}

void dfs1(int c, int p){
    sz[c] = 1;
    for(auto &n: child[c]){
        dep[n] = dep[c] + 1; par[n] = c;
        dfs1(n, c);
        sz[c] += sz[n];
        if(sz[n] > sz[child[c][0]]) swap(n, child[c][0]);
    }
}

int idx = 0;
void dfs2(int c, int p){
    in[c] = idx++;
    for(auto n: child[c]){
        if(n == child[c][0]) top[n] = top[c];
        else top[n] = n;
        dfs2(n, c);
    }
    out[c] = idx;
}

void query1(ll X, ll V){
    LST.update(in[X], out[X]-1, {1, V});
}

void query2(ll X, ll Y, ll V){
    while(top[X] != top[Y]){
        if(dep[top[X]] < dep[top[Y]]) swap(X, Y);
        LST.update(in[top[X]], in[X], {1, V});
        X = par[top[X]];
    }
    if(dep[X] > dep[Y]) swap(X, Y);
    LST.update(in[X], in[Y], {1, V});
}

void query3(ll X, ll V){
    LST.update(in[X], out[X]-1, {V, 0});
}

void query4(ll X, ll Y, ll V){
    while(top[X] != top[Y]){
        if(dep[top[X]] < dep[top[Y]]) swap(X, Y);
        LST.update(in[top[X]], in[X], {V, 0});
        X = par[top[X]];
    }
    if(dep[X] > dep[Y]) swap(X, Y);
    LST.update(in[X], in[Y], {V, 0});
}

ll query5(ll X){
    return LST.query(in[X], out[X]-1);
}

ll query6(ll X, ll Y){
    ll ret = 0;
    while(top[X] != top[Y]){
        if(dep[top[X]] < dep[top[Y]]) swap(X, Y);
        ret += LST.query(in[top[X]], in[X]);
        X = par[top[X]];
    }
    if(dep[X] > dep[Y]) swap(X, Y);
    ret += LST.query(in[X], in[Y]);
    return ret;
}

void solve(){
    cin >> N >> Q;
    rep(i, 0, N-1){
        int u, v; cin >> u >> v; u--, v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    maketree(0, -1);
    dfs1(0, -1);
    dfs2(0, -1);
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            ll X, V; cin >> X >> V; X--;
            // 금고 X의 서브트리에 V 더하기
            query1(X, V);
        }
        else if(op == 2){
            ll X, Y, V; cin >> X >> Y >> V; X--, Y--;
            // 금고 X에서 금고 Y로 가는 경로에 V 더하기
            query2(X, Y, V);
        }
        else if(op == 3){
            ll X, V; cin >> X >> V; X--;
            // 금고 X의 서브트리에 있는 금고들의 값에 V 곱하기
            query3(X, V);
        }
        else if(op == 4){
            ll X, Y, V; cin >> X >> Y >> V; X--, Y--;
            // 금고 X에서 금고 Y로 가는 경로에 있는 금고들의 값에 V 곱하기
            query4(X, Y, V);
        }
        else if(op == 5){
            ll X; cin >> X; X--;
            // 금고 X의 서브트리에 있는 금고들의 돈의 합 출력
            cout << query5(X) << '\n';
        }
        else{
            ll X, Y; cin >> X >> Y; X--, Y--;
            // 금고 X에서 금고 Y로 가는 경로에 있는 금고들의 돈의 합 출력
            cout << query6(X, Y) << '\n';
        }

        // rep(i, 0, N) cout << LST.query(in[i], in[i]) << ' ';
        // cout << '\n';
    }

    // cout << '\n';
    // rep(i, 0, N){
    //     cout << i << ' ' << in[i] << ' ' << child[in[i]].size() << '\n';
    //     for(auto n: child[in[i]]) cout << n << ' ';
    //     cout << '\n';
    // }
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