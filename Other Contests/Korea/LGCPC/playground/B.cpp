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

int N, M;
int group[300000];
vector<int> links[300000];

bool dfs(int cur){
    for(auto nxt: links[cur]){
        if(group[nxt] == -1){
            group[nxt] = 1 - group[cur];
            if(!dfs(nxt)) return false;
        }
        else if(group[nxt] == group[cur]) return false;
    }
    return true;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, M){
        int x, y; cin >> x >> y;
        x--; y--;
        links[x].push_back(y);
        links[y].push_back(x);
    }
    fill(group, group+N, -1);

    bool flag = true;
    rep(i, 0, N){
        if(group[i] == -1){
            group[i] = 0;
            if(!dfs(i)) flag = false;
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";

    rep(i, 0, N) links[i].clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}