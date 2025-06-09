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

const ll mxN = 404;
struct edg{ ll pos, cap, rev; };
vector<edg> gph[mxN];
void add_edge(ll s, ll e, ll x){
    gph[s].push_back({e, x, (ll)gph[e].size()});
    gph[e].push_back({s, 0, (ll)gph[s].size()-1});
}
ll dist[mxN], par[mxN];
bool bfs(ll S, ll T){
    fill(dist, dist + mxN, 0);
    fill(par, par + mxN, 0);
    queue<ll> Q;
    Q.push(S);
    dist[S] = 1;
    while(!Q.empty()){
        ll x = Q.front(); Q.pop();
        for(auto &i : gph[x]){
            if(i.cap > 0 && !dist[i.pos]){
                dist[i.pos] = dist[x] + 1;
                Q.push(i.pos);
            }
        }
    }
    return dist[T] > 0;
}

ll dfs(ll x, ll T, ll flw){
    if(x == T) return flw;
    for(; par[x] < gph[x].size(); par[x]++){
        edg &i = gph[x][par[x]];
        if(i.cap > 0 && dist[i.pos] == dist[x] + 1){
            ll df = dfs(i.pos, T, min(flw, i.cap));
            if(df){
                i.cap -= df;
                gph[i.pos][i.rev].cap += df;
                return df;
            }
        }
    }
    return 0;
}

ll max_flow(ll S, ll T){
    ll ret = 0;
    while(bfs(S, T)){
        ll r;
        while((r = dfs(S, T, 2e9))) ret += r;
    }
    return ret;
}

bool check[mxN];

void solve(){
    ll N, M; cin >> N >> M;
    ll S, T; cin >> S >> T;
    rep(i, 1, N+1){
        ll x; cin >> x;
        add_edge(i*2, i*2+1, x);
    }
    rep(i, 0, M){
        ll a, b; cin >> a >> b;
        add_edge(a*2+1, b*2, 2e9);
        add_edge(b*2+1, a*2, 2e9);
    }
    ll MF = max_flow(S*2, T*2+1);

    queue<int> Q;
    Q.push(S*2);
    check[S*2] = 1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto &i : gph[cur]){
            if(i.cap > 0 && !check[i.pos]){
                check[i.pos] = 1;
                Q.push(i.pos);
            }
        }
    }

    for(int i = 1; i <= N; i++) if(check[i*2] && !check[i*2+1]) cout << i << ' ';
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