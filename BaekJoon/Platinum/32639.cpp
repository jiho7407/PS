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

int N;
vector<int> links[100000];
int color[100000], reqL[100000], reqR[100000];
bool used[100000];

vector<pii> v[100001]; // v[i] : L, v[i][j] : {R, idx}

void dfs(int c, int p){
    if(color[c]){
        reqL[c] = max(reqL[c], color[c]);
        reqR[c] = min(reqR[c], color[c]);
    }

    used[color[c]] = true;
    for(auto n: links[c]){
        if(n == p) continue;
        reqR[n] = min(reqR[n], reqR[c]-1);
        dfs(n, c);
        reqL[c] = max(reqL[c], reqL[n]+1);
    }

    if(color[c] == 0) v[reqL[c]].push_back({reqR[c], c});
}

void dfs2(int c, int p){
    for(auto n: links[c]){
        if(n == p) continue;
        if(color[c] < color[n]){
            cout << "NO";
            exit(0);
        }
        dfs2(n, c);
    }
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> color[i];
    if(color[0] != 0 && color[0] != N){
        cout << "NO";
        return;
    }
    color[0] = N;
    fill(reqL, reqL+N, 1);
    fill(reqR, reqR+N, N);
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    dfs(0, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // rep(i, 0, N) cout << reqL[i] << ' ' << reqR[i] << '\n';
    rep(i, 1, N+1){
        for(auto p: v[i]) pq.push(p);
        if(used[i]) continue;
        if(pq.empty()){
            cout << "NO";
            return;
        }
        auto [r, idx] = pq.top(); pq.pop();
        color[idx] = i;
    }
    dfs2(0, -1);
    
    cout << "YES\n";
    rep(i, 0, N) cout << color[i] << ' ';
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