#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct UF_rb{
    vector<int> par, dep, savev;
    stack<pair<pii, int>> stk;
    int dsu_cnt;

    void init(int N){
        par.resize(N);
        dep.resize(N);
        dsu_cnt = N;
        savev.push_back(0);
        rep(i, 0, N) par[i] = i;
        rep(i, 0, N) dep[i] = 0;
    }

    int find(int x){
        if(par[x] == x) return x;
        return find(par[x]);
    }

    bool merge(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        if(dep[a] > dep[b]) swap(a, b); // b가 더 깊게
        par[a] = b;

        if(dep[a] == dep[b]){
            dep[b]++;
            stk.push({{a, b}, 1});
        }
        else stk.push({{a, b}, 0});

        dsu_cnt--;
        savev.back()++;
        return true;
    }

    void save(){
        savev.push_back(0);
    }

    void rollback(){
        int cnt = savev.back(); savev.pop_back();
        while(cnt--){
            auto [p, d] = stk.top(); stk.pop();
            auto [a, b] = p;
            par[a] = a;
            if(d) dep[b]--;
            dsu_cnt++;
        }
    }
}UF;

int N, M, Q, sqQ;
vector<tii> edges;
int ans[100010];
vector<tuple<int, int, int, int>> query[500];

void solve(){
    cin >> N >> M;

    rep(i, 0, M){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        edges.push_back({c, a, b});
    }
    fill(ans, ans+100000, -1);
    cin >> Q; sqQ = sqrt(Q)+10;
    rep(i, 0, Q){
        int op, a, b; cin >> op >> a >> b;
        a--;
        query[i/sqQ].push_back({idx, op, a, b});
    }

    rep(i, 0, sqQ){
        vector<bool> is_change(M, false);
        for(auto [idx, op, a, b]: query[i]){
            if(op == 1) is_change[a] = true;
        }
        vector<int> NCedges, Cedges;
        rep(i, 0, N){
            if(is_change[i]) Cedges.push_back(i);
            else NCedges.push_back(i);
        }

        UF.init(N);
        vector<tii> tmp_edges;


        for(auto [idx, op, a, b]: query[i]) if(op == 1) edges[idx] = {idx, a, b};
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