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

vector<int> links[100000];
int child[100000];
vector<pii> ans, query[100000];

void initDfs(int cur, int par){
    child[cur] = 1;
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        initDfs(nxt, cur);
        child[cur] += child[nxt];
    }
}

void reRootDfs(int cur, int par){
    for(auto [idx, x]: query[cur]) ans.push_back({idx, child[x]});
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        child[cur] -= child[nxt];
        child[nxt] += child[cur];
        reRootDfs(nxt, cur);
        child[nxt] -= child[cur];
        child[cur] += child[nxt];
    }
}

void solve(){
    int N, Q, R; cin >> N >> Q >> R; R--;
    rep(i, 0, N-1){
        int u, v; cin >> u >> v;
        u--, v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    rep(i, 0, Q){
        int op, x; cin >> op >> x; x--;
        if(op == 0) R = x;
        else query[R].push_back({i, x});
    }

    initDfs(R, -1);
    reRootDfs(R, -1);
    sort(ans.begin(), ans.end());
    for(auto [idx, x]: ans) cout << x << '\n';

    // 초기화
    rep(i, 0, N) links[i].clear();
    rep(i, 0, N) child[i] = 0;
    rep(i, 0, N) query[i].clear();
    ans.clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << ":\n";
        solve();
    }
    return 0;
}