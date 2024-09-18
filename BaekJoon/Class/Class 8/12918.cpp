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

const int mxN = 202;
int N;
pii thing[100];

// 최소비용 최대유량
// MCMF
struct MCMF{
    struct Edge{
        int to, cap, inv;
        double cost;

        Edge(int to, int cap, int inv, double cost):to(to), cap(cap), inv(inv), cost(cost){}
    };

    vector<Edge> edge[mxN];
    int S, T;

    void clear(){
        rep(i, 0, mxN) edge[i].clear();
    }

    void add(int s, int e, int cap, double cost){
        edge[s].push_back(Edge(e, cap, edge[e].size(), cost));
        edge[e].push_back(Edge(s, 0, edge[s].size()-1, -cost));
    }

    void setST(int s, int t){
        S = s, T = t;
    }

    double dist[mxN];
    int pa[mxN], pe[mxN]; 
    bool inQ[mxN];

    bool spfa(){
        fill(dist, dist+mxN, 1e9);
        fill(inQ, inQ+mxN, 0);

        queue<int> q;
        q.push(S);
        dist[S] = 0;
        inQ[S] = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(int i=0; i<edge[cur].size(); i++){
                int nxt = edge[cur][i].to;
                int cap = edge[cur][i].cap;
                double cost = edge[cur][i].cost;
                if(cap>0 && dist[nxt]>dist[cur]+cost + 1e-9){
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
        return dist[T] != 1e9;
    }

    double match(){
        double ret = 0;
        rep(i, 0, N){
            spfa();
            ret += dist[T];
            for(int j=T; j!=S; j=pa[j]){
                int inv = pe[j];
                edge[pa[j]][inv].cap--;
                edge[j][edge[pa[j]][inv].inv].cap++;
            }
        }
        return ret;
    }
}MCMF;

double dist(pii a, pii b){
    double dx = (double)a.first+b.first;
    double dy = (double)a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> thing[i].first >> thing[i].second;
    
    MCMF.clear();
    MCMF.setST(N<<1, N<<1|1);
    rep(i, 0, N){
        MCMF.add(MCMF.S, i<<1, 1, 0);
        MCMF.add(i<<1|1, MCMF.T, 1, 0);
    }
    rep(i, 0, N) rep(j, 0, N){
        if(i == j) MCMF.add(i<<1, j<<1|1, 1, abs(thing[i].first));
        else MCMF.add(i<<1, j<<1|1, 1, dist(thing[i], thing[j])/2);
    }

    cout << fixed << setprecision(3) << MCMF.match() << '\n';
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