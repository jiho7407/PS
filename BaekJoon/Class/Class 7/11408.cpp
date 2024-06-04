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

const int mxN = 802;
const int INF = 1e9;
const int SR = 800, SK = 801;
int N, M;
int cap[mxN][mxN], flow[mxN][mxN], cost[mxN][mxN];
vector<int> links[mxN];

int prv[mxN], dist[mxN];
bool inQ[mxN];

bool SPFA(){
    fill_n(&dist[0], mxN, INF);
    fill_n(&prv[0], mxN, -1);
    fill_n(&inQ[0], mxN, false);
    dist[SR] = 0;
    inQ[SR] = true;
    queue<int> q;
    q.push(SR);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        inQ[cur] = false;
        for(auto &nxt: links[cur]){
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
    return prv[SK] != -1;
}

void solve(){
    cin >> N >> M;
    fill_n(&cap[0][0], mxN*mxN, 0);
    fill_n(&flow[0][0], mxN*mxN, 0);
    fill_n(&cost[0][0], mxN*mxN, 0);
    rep(i, 0, N){
        cap[SR][i] = 1;
        links[SR].push_back(i);
        links[i].push_back(SR);
    }
    rep(i, 0, M){
        cap[i+400][SK] = 1;
        links[i+400].push_back(SK);
        links[SK].push_back(i+400);
    }
    rep(i, 0, N){
        int a; cin >> a;
        rep(j, 0, a){
            int nxt; cin >> nxt; nxt += 399;
            cap[i][nxt] = 1;
            links[i].push_back(nxt);
            links[nxt].push_back(i);
            int c; cin >> c;
            cost[i][nxt] = c;
            cost[nxt][i] = -c;
        }
    }
    int ans = 0, cnt = 0;
    while(SPFA()){
        for(int i = SK; i != SR; i = prv[i]){
            flow[prv[i]][i]++;
            flow[i][prv[i]]--;
            ans += cost[prv[i]][i];
        }
        cnt++;
    }
    cout << cnt << '\n' << ans << '\n';
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