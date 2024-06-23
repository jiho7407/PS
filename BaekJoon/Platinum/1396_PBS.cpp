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

const int mxN = 100000;
int N, M, Q;
vector<tuple<int, int, int>> edges;
vector<pii> query;

int L[mxN], R[mxN];
vector<int> pbs[mxN];
int ans[mxN][2];

struct UnionFind{
    int par[mxN], size[mxN];

    void init(int N){
        rep(i, 0, N) par[i] = i;
        fill(size, size+N, 1);
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(x > y) swap(x, y);
        par[y] = x;
        size[x] += size[y];
    }
}UF;

void solve(){
    cin >> N >> M;
    rep(i, 0, M){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    cin >> Q;
    rep(i, 0, Q){
        int u, v; cin >> u >> v;
        u--, v--;
        if(u>v) swap(u, v);
        query.push_back({u, v});
    }

    rep(i, 0, Q){ L[i] = 0, R[i] = M; }
    
    while(1){
        rep(i, 0, M) pbs[i].clear();
        bool flag = false;
        rep(i, 0, Q) if(L[i] != R[i]){
            pbs[(L[i]+R[i])/2].push_back(i);
            flag = true;
        }
        if(!flag) break;

        UF.init(N);
        rep(i, 0, M){
            auto [w, u, v] = edges[i];
            UF.merge(u, v);
            for(auto q:pbs[i]){
                auto [u, v] = query[q];
                if(UF.find(u) == UF.find(v)){
                    R[q] = i;
                    ans[q][0] = w;
                    ans[q][1] = UF.size[UF.find(u)];
                }
                else L[q] = i+1;
            }
        }
    }

    rep(i, 0, Q){
        if(L[i] == M) cout << "-1\n";
        else cout << ans[i][0] << " " << ans[i][1] << "\n";
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