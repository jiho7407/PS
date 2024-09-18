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

const ll INF = 1e15;
const ll mxN = 300;
// 최소비용 최대유량
// MCMF
struct MCMF{
    struct Edge{
        ll to, cap, cost, inv;
    };

    vector<Edge> edge[mxN];
    ll S, T;

    void clear(){
        rep(i, 0, mxN) edge[i].clear();
    }

    void add(ll s, ll e, ll cap, ll cost){
        edge[s].push_back({e, cap, cost, (ll)edge[e].size()});
        edge[e].push_back({s, 0, -cost, (ll)edge[s].size()-1});
    }

    void setST(ll s, ll t){
        S = s, T = t;
    }

    ll dist[mxN], pa[mxN], pe[mxN]; 
    bool inQ[mxN];

    bool spfa(){
        fill(dist, dist+mxN, INF);
        fill(inQ, inQ+mxN, 0);

        queue<ll> q;
        q.push(S);
        dist[S] = 0;
        inQ[S] = 1;
        while(!q.empty()){
            ll cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(ll i=0; i<edge[cur].size(); i++){
                auto [nxt, cap, cost, inv] = edge[cur][i];
                if(cap>0 && dist[nxt]>dist[cur]+cost){
                    dist[nxt] = dist[cur]+cost;
                    pa[nxt] = cur;
                    pe[nxt] = i;
                    if(!inQ[nxt]){
                        q.push(nxt);
                        inQ[nxt] = 1;
                    }
                }
            }
        }
        return dist[T] != INF;
    }

    ll match(ll K, ll CC){
        ll ret = K*INF;
        ll ans = INF;
        while(spfa()){
            ll cap = INF;
            for(ll i=T; i!=S; i=pa[i]){
                cap = min(cap, edge[pa[i]][pe[i]].cap);
            }
            ret += dist[T]*cap;
            if(ret < INF) ans = min(ans, ret);
            for(ll i=T; i!=S; i=pa[i]){
                ll inv = pe[i];
                edge[pa[i]][inv].cap -= cap;
                edge[i][edge[pa[i]][inv].inv].cap += cap;
            }
            ret += CC;
        }
        return ans;
    }
}MCMF;

ll N, M, K;
ll C[500][500], dstt[500][500];
vector<pii> points;

int dx[2] = {0, 1}, dy[2] = {1, 0};

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N) rep(j, 0, M) cin >> C[i][j];
    rep(i, 0, K){
        int x, y;
        cin >> x >> y;
        x--, y--;
        points.push_back({x, y});
    }
    points.push_back({0, 0});
    points.push_back({N-1, M-1});
    sort(points.begin(), points.end());
    rep(i, 0, K+2){
        fill_n(&dstt[0][0], 500*500, INF);
        auto [x, y] = points[i];
        dstt[x][y] = 0;

        rep(cx, x, N) rep(cy, y, M){
            rep(d, 0, 2){
                int nx = cx+dx[d], ny = cy+dy[d];
                if(nx>=N || ny>=M) continue;
                dstt[nx][ny] = min(dstt[nx][ny], dstt[cx][cy]+C[cx][cy]);
            }
        }

        rep(j, 0, K+2){
            if(i == j) continue;
            if(i == 0 && j == K+1) continue;
            ll cc = dstt[points[j].first][points[j].second];
            if(cc >= INF) continue;
            int st = 2*i+1, ed = 2*j;
            MCMF.add(st, ed, 1, cc);
        }
    }
    rep(i, 0, K+2) MCMF.add(2*i, 2*i+1, 1, -INF);
    MCMF.setST(1, 2*K+2);

    cout << MCMF.match(K, C[N-1][M-1]) << '\n';
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