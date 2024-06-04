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

const int mxN = 202; // 0~99: 사람, 100~199: 서점, 200: source, 201: sink
const int INF = 1e9;
const int SR = 200, SK = 201;
int N, M;
int capacity[mxN][mxN], flow[mxN][mxN], cost[mxN][mxN];
vector<int> links[mxN];

int prv[mxN], dist[mxN];
bool inQ[mxN];
queue<int> q;

bool SPFA(){
    fill_n(&dist[0], mxN, INF);
    fill_n(&prv[0], mxN, -1);
    fill_n(&inQ[0], mxN, false);
    dist[SR] = 0;
    inQ[SR] = true;
    q.push(SR);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        inQ[cur] = false;
        for(auto &nxt: links[cur]){
            if(capacity[cur][nxt] - flow[cur][nxt] > 0 && dist[nxt] > dist[cur] + cost[cur][nxt]){
                dist[nxt] = dist[cur] + cost[cur][nxt];
                prv[nxt] = cur;
                if(!inQ[nxt]){
                    q.push(nxt);
                    inQ[nxt] = true;
                }
            }
        }
    }
    return prv[SK] != -1;
}

void solve(){
    fill_n(&capacity[0][0], mxN*mxN, 0);
    fill_n(&flow[0][0], mxN*mxN, 0);
    fill_n(&cost[0][0], mxN*mxN, 0);

    cin >> N >> M;
    rep(i, 0, N){
        int a; cin >> a;
        capacity[200][i] = a;
        links[200].push_back(i);
        links[i].push_back(200);
    }
    rep(i, 0, M){
        int b; cin >> b;
        capacity[100+i][201] = b;
        links[100+i].push_back(201);
        links[201].push_back(100+i);
    }
    rep(i, 0, M){
        rep(j, 0, N){
            int c; cin >> c;
            cost[j][100+i] = c;
            cost[100+i][j] = -c;
            capacity[j][100+i] = INF;
            links[j].push_back(100+i);
            links[100+i].push_back(j);
        }
    }

    int ans = 0;
    while(SPFA()){
        int mxf = INF;
        for(int i = SK; i!=SR; i=prv[i]){
            mxf = min(mxf, capacity[prv[i]][i] - flow[prv[i]][i]);
        }

        for(int i = SK; i!=SR; i=prv[i]){
            ans += mxf * cost[prv[i]][i];
            flow[prv[i]][i] += mxf;
            flow[i][prv[i]] -= mxf;
        }
    }

    cout << ans << '\n';
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