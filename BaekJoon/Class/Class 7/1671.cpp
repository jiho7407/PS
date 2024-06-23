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

const int SOURCE = 0, SINK = 101;
int N;
vector<tuple<int, int, int>> shark;
int cap[102][102], flow[102][102]; // 0 : source, 1~100: shark, 101: sink
vector<int> links[102];
int prv[102];

bool eatable(int i, int j){
    auto [a1, a2, a3] = shark[i];
    auto [b1, b2, b3] = shark[j];
    if(a1 >= b1 && a2 >= b2 && a3 >= b3) return true;
    return false;
}

bool bfs(){
    fill(prv, prv+102, -1);
    queue<int> q;
    q.push(SOURCE);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt: links[cur]){
            if(prv[nxt] != -1) continue;
            if(cap[cur][nxt] - flow[cur][nxt] <= 0) continue;
            prv[nxt] = cur;
            q.push(nxt);
            if(nxt == SINK) return true;
        }
    }
    return false;
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, b, c; cin >> a >> b >> c;
        shark.push_back({a, b, c});
    }
    sort(shark.begin(), shark.end(), greater<tuple<int, int, int>>());
    rep(i, 0, N) rep(j, i+1, N){
        if(!eatable(i, j)) continue;
        cap[i+1][j+51] = 1;
        links[i+1].push_back(j+51);
        links[j+51].push_back(i+1);
    }
    rep(i, 0, N){
        cap[SOURCE][i+1] = 2;
        links[SOURCE].push_back(i+1);
        links[i+1].push_back(SOURCE);
        cap[i+51][SINK] = 1;
        links[i+51].push_back(SINK);
        links[SINK].push_back(i+51);
    }
    int cnt = 0;
    while(bfs()){
        for(int i = SINK; i != SOURCE; i = prv[i]){
            flow[prv[i]][i]++;
            flow[i][prv[i]]--;
        }
        cnt++;
    }
    cout << N - cnt << '\n';
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