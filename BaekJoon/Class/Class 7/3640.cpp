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

const int mxN = 2000;
// const int SR = 2000, SK = 2001;
int V, E;
vector<int> links[mxN];
int cap[mxN][mxN], flow[mxN][mxN], cost[mxN][mxN];

int prv[mxN], dist[mxN];
bool inQ[mxN];
queue<int> q;

bool SPFA(){
    fill(prv, prv+mxN, -1);
    fill(dist, dist+mxN, 1e9);
    fill(inQ, inQ+mxN, false);
    dist[0] = 0;
    q.push(0);
    inQ[0] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        inQ[cur] = false;
        for(auto &nxt : links[cur]){
            if(cap[cur][nxt] - flow[cur][nxt] > 0 && dist[nxt] > dist[cur] + cost[cur][nxt]){
                dist[nxt] = dist[cur] + cost[cur][nxt];
                prv[nxt] = cur;
                if(!inQ[nxt]){
                    q.push(nxt);
                    inQ[nxt] = true;
                }
            }
        }
    }
    return prv[2*(V-1)+1] != -1;
}

void solve(){
    while(cin >> V >> E){
        fill_n(&cap[0][0], mxN*mxN, 0);
        fill_n(&flow[0][0], mxN*mxN, 0);
        fill_n(&cost[0][0], mxN*mxN, 0);
        rep(i, 0, V){
            links[i*2].push_back(i*2+1);
            links[i*2+1].push_back(i*2);
            cap[i*2][i*2+1] = 1;
        }
        cap[0][1] = 2;
        cap[2*(V-1)][2*(V-1)+1] = 2;
        rep(i, 0, E){
            int a, b, c; cin >> a >> b >> c; a--; b--;
            links[a*2+1].push_back(b*2);
            links[b*2].push_back(a*2+1);
            cap[a*2+1][b*2] = 1;
            cost[a*2+1][b*2] = c;
            cost[b*2][a*2+1] = -c;
        }
        int ans = 0;
        while(SPFA()){
            int f = 1e9;
            for(int i = 2*(V-1)+1; i != 0; i = prv[i]){
                f = min(f, cap[prv[i]][i] - flow[prv[i]][i]);
            }
            for(int i = 2*(V-1)+1; i != 0; i = prv[i]){
                ans += f * cost[prv[i]][i];
                flow[prv[i]][i] += f;
                flow[i][prv[i]] -= f;
            }
        }
        cout << ans << endl;

        

        rep(i, 0, mxN) links[i].clear();
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}