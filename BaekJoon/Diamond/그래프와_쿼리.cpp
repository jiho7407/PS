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

int N, M;
pii ans[100100];
vector<pii> tree[400100];
map<pii, int> mp;

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

    bool same(int a, int b){
        return find(a) == find(b);
    }
}UF(0);

void update(int idx, int l, int r, int s, int e, pii val){
    if(e < l || r < s) return;
    if(s <= l && r <= e){
        tree[idx].push_back(val);
        return;
    }
    int m = (l+r)>>1;
    update(idx<<1, l, m, s, e, val);
    update(idx<<1|1, m+1, r, s, e, val);
}

void dfs(int idx, int l, int r){
    int cnt = 0;
    for(auto [a, b]: tree[idx]) UF.merge(a, b), cnt++;
    if(l == r){
        auto [a, b] = ans[l];
        if(a) cout << UF.same(a, b) << '\n';
    }
    else{
        int m = (l+r)>>1;
        dfs(idx<<1, l, m);
        dfs(idx<<1|1, m+1, r);
    }
    UF.rollback(cnt);
}

void solve(){
    cin >> N >> M;
    UF = UnionFindRollback(N+1);
    rep(i, 1, M+1){
        int op, a, b; cin >> op >> a >> b;
        if(a > b) swap(a, b);
        if(op == 1) mp[{a, b}] = i;
        else if(op == 2) update(1, 1, M, mp[{a, b}], i, {a, b}), mp.erase({a, b});
        else ans[i] = {a, b};
    }
    for(auto [a, b]: mp) update(1, 1, M, b, M+1, a);
    dfs(1, 1, M);
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