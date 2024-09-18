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

int N, K;
vector<int> links[800];
int AM[800], BM[400];
bool visited[800];

bool dfs(int a){
    if(visited[a]) return 0;
    visited[a] = 1;
    for(auto b:links[a]){
        if(BM[b] == -1 || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return 1;
        }
    }
    return 0;
}

void solve(){
    cin >> N >> K;
    rep(i, 0, N) rep(j, 0, K){
        int a; cin >> a;
        if(a) links[j].push_back(i);
    }
    fill(AM, AM+K, -1);
    fill(BM, BM+N, -1);

    for(int i = K-1; i >= 0; i--){
        fill(visited, visited+K, 0);
        dfs(i);
    }

    int ans = 0;
    rep(i, 0, K){
        if(AM[i] == -1) continue;
        if(ans*2+1 <= i) ans++;
    }
    cout << ans;
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