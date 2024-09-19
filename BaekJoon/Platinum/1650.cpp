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

const int mxN = 2000;
int N, M;

// MCMF
struct MCMF{
    struct Edge{
        int to, cap, cost, inv;
    };

    vector<Edge> edge[mxN];
    int S, T;

    void clear(){
        rep(i, 0, mxN) edge[i].clear();
    }

    void add(int s, int e, int cap, int cost){
        edge[s].push_back({e, cap, cost, (int)edge[e].size()});
        edge[e].push_back({s, 0, -cost, (int)edge[s].size()-1});
    }

    void setST(int s, int t){
        S = s, T = t;
    }

    int dist[mxN], pa[mxN], pe[mxN]; 
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
        return dist[T] != 1e9;
    }

    int match(){
        int ret = 0;
        rep(i, 0, 2){
            spfa();
            for(int i = T; i != S; i = pa[i]){
                int inv = pe[i];
                ret += edge[pa[i]][inv].cost;
                edge[pa[i]][inv].cap--;
                edge[i][edge[pa[i]][inv].inv].cap++;
            }
        }
        return ret;
    }
}MCMF;

void solve(){
    cin >> N >> M;
    MCMF.clear();
    MCMF.setST(1, (N-1)<<1);

    rep(i, 0, N) MCMF.add(i<<1, i<<1|1, 100, 0);
    rep(i, 0, M){
        int P, Q, L; cin >> P >> Q >> L;
        P--, Q--;
        MCMF.add(P<<1|1, Q<<1, 1, L);
        MCMF.add(Q<<1|1, P<<1, 1, L);
    }

    cout << MCMF.match();
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