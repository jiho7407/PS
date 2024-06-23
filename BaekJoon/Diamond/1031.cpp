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

const int source = 100, sink = 101;
int N, M;
int cap[102][102], flow[102][102];
vector<int> links[102];
int prv[102];

bool bfs(){
    fill(prv, prv+102, -1);
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto next : links[cur]){
            if(cap[cur][next] - flow[cur][next] > 0 && prv[next] == -1){
                q.push(next);
                prv[next] = cur;
                if(next == sink) return true;
            }
        }
    }
    return false;
}

bool bfs2(int a, int b){
    fill(prv, prv+102, -1);
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto next : links[cur]){
            if(cur < a || (cur==a && next < b)) continue; // 사전순으로 앞서지면 컷
            if(cap[cur][next] - flow[cur][next] > 0 && prv[next] == -1){
                q.push(next);
                prv[next] = cur;
            }
        }
    }
    return prv[b] != -1;
}

void solve(){
    cin >> N >> M;
    int sumA = 0, sumB = 0;
    rep(i, 0, N){
        int a; cin >> a; sumA += a;
        cap[source][i] = a;
        links[source].push_back(i);
        links[i].push_back(source);
    }
    rep(i, 0, M){
        int b; cin >> b; sumB += b;
        cap[i+50][sink] = b;
        links[i+50].push_back(sink);
        links[sink].push_back(i+50);
    }
    if(sumA != sumB){ cout << -1; return; }

    rep(i, 0, N) rep(j, 0, M){
        cap[i][j+50] = 1;
        links[i].push_back(j+50);
        links[j+50].push_back(i);
    }

    int total = 0;
    while(bfs()){
        for(int i = sink; i != source; i = prv[i]){
            flow[prv[i]][i]++;
            flow[i][prv[i]]--;
        }
        total++;
    }
    if(total != sumA){ cout << -1; return; }
    rep(i, 0, N) rep(j, 50, 50+M){
        if(flow[i][j] == 0) continue;
        if(!bfs2(i, j)) continue;
        flow[i][j] = 0;
        flow[j][i] = 0;
        for(int k = j; k != i; k = prv[k]){
            flow[prv[k]][k]++;
            flow[k][prv[k]]--;
        }
    }
    rep(i, 0, N){
        rep(j, 0, M) cout << (int)flow[i][j+50];
        cout << '\n';
    }
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