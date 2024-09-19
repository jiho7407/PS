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

struct UnionFind{
    int par[100000], cnt[100000];
    int group;

    void init(int N){
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
        return true;
    }
}UF;

int N, M;
vector<tuple<int, int, ll>> edges;
bool used[200000];

vector<pair<int, ll>> links[100000];
int depth[100000], parent[100000][20];
ll val[100000][20];

bool cmp(tuple<int, int, ll> a, tuple<int, int, ll> b){
    return get<2>(a) < get<2>(b);
}

void dfs(int c, int p, int d){
    depth[c] = d;
    parent[c][0] = p;
    for(auto [nxt, w] : links[c]){
        if(nxt == p) continue;
        val[nxt][0] = w;
        dfs(nxt, c, d+1);
    }
}

ll LCA(int a, int b){
    ll ret = 0;
    if(depth[a] > depth[b]) swap(a, b);
    for(int i = 19; i >= 0; i--){
        if(depth[b] - depth[a] >= (1 << i)){
            ret = max(ret, val[b][i]);
            b = parent[b][i];
        }
    }
    if(a == b) return ret;
    for(int i = 19; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            ret = max({ret, val[a][i], val[b][i]});
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return max({ret, val[a][0], val[b][0]});
}

void solve(){
    // 입력받기
    cin >> N >> M;
    rep(i, 0, M){
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), cmp);
    UF.init(N);

    // MST 만들기
    rep(i, 0, M){
        auto [u, v, w] = edges[i];
        if(UF.merge(u, v)) used[i] = true;
    }

    // 첫 MST를 제외하고 다른 MST 만들고, 이를 트리로 만들기
    UF.init(N);
    rep(i, 0, M){
        if(used[i]) continue;
        auto [u, v, w] = edges[i];
        if(!UF.merge(u, v)) continue;
        links[u].push_back({v, w});
        links[v].push_back({u, w});
    }
    
    if(UF.group > 1){
        cout << "-1\n";
        return;
    }

    // LCA 만들기
    dfs(0, -1, 0);
    rep(j, 1, 20) rep(i, 0, N){
        if(parent[i][j-1] == -1) continue;
        parent[i][j] = parent[parent[i][j-1]][j-1];
        val[i][j] = max(val[i][j-1], val[parent[i][j-1]][j-1]);
    }

    // 답 구하기
    ll ans = 0;
    rep(i, 0, M){
        if(!used[i]) continue;
        auto [u, v, w] = edges[i];
        ans += LCA(u, v) - w + 1;
    }
    cout << ans << '\n';
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