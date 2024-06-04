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

int N, M;
vector<int> links[1000];
bool visited[1000];
int BM[1000];

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto nxt: links[a]){
        if(BM[nxt] == -1 || dfs(BM[nxt])){
            BM[nxt] = a;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        links[a].push_back(b);
    }
    fill(BM, BM+1000, -1);
    int ans = 0;
    rep(i, 0, N){
        fill(visited, visited+1000, false);
        if(dfs(i)) ans++;
    }
    cout << ans << '\n';

    rep(i, 0, 1000) links[i].clear();
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}