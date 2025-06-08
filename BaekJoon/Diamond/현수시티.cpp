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

struct UnionFindRollback{
    int group;
    vector<int> par, sz;
    vector<pii> history;
    UnionFindRollback(int N): group(N), par(N), sz(N, 1){
        iota(par.begin(), par.end(), 0);
    }

    int find(int x){
        while(x != par[x]) x = par[x];
        return x;
    }

    bool merge(int a, int b){
        a = find(a); b = find(b);
        if(a == b){
            history.push_back({-1, -1});
            return false;
        }
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        group--;
        history.push_back({a, b});
        return true;
    }

    void rollback(int cnt){
        while(cnt--){
            auto [a, b] = history.back(); history.pop_back();
            if(a == -1) continue;
            par[b] = b;
            sz[a] -= sz[b];
            group++;
        }
    }
}UF(0);
map<pii, int> mp;
vector<pii> tree[600100];
pii query[300100];

void update(int idx, int l, int r, int s, int e, pii val){
    if(e < l || r < s) return;
    if(s <= l && r <= e){
        tree[idx].push_back(val);
        return;
    }
    int m = l + r >> 1;
    update(idx<<1, l, m, s, e, val);
    update(idx<<1|1, m+1, r, s, e, val);
}

void dfs(int idx, int l, int r){
    for(auto [a, b]: tree[idx]) UF.merge(a, b);
    if(l == r){
        auto [a, b] = query[l];
        if(a) cout << ((UF.find(a) == UF.find(b)) ? "YES\n" : "NO\n");
    }
    else{
        int m = l + r >> 1;
        dfs(idx<<1, l, m);
        dfs(idx<<1|1, m+1, r);
    }
    UF.rollback(tree[idx].size());
}

void solve(){
    int N, M; cin >> N >> M;
    vector<pii> roads(M);
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        roads[i] = {a, b};
    }
    rep(i, 0, M){
        bool state; cin >> state;
        if(state) mp[roads[i]] = 0;
    }
    int Q; cin >> Q;
    rep(i, 1, Q+1){
        int op; cin >> op;
        if(op == 1){
            int idx; cin >> idx; idx--;
            if(mp.find(roads[idx]) == mp.end()) mp[roads[idx]] = i;
            else update(1, 0, Q, mp[roads[idx]], i-1, roads[idx]), mp.erase(roads[idx]);
        }
        else{
            int a, b; cin >> a >> b;
            query[i] = {a, b};
        }
    }
    for(auto [k, v]: mp) update(1, 0, Q, v, Q, k);
    UF = UnionFindRollback(N+1);
    dfs(1, 0, Q);
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