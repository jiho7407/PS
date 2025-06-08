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
vector<int> links[101];
set<pii> st;
void dfs(int root, int cur, int par, int dist){
    if(dist > 2 && dist%2 == 0){
        st.insert({min(root, cur), max(root, cur)});
    }
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        dfs(root, nxt, cur, dist+1);
    }
}

void solve(){
    int N; cin >> N;
    rep(i, 0, N-1){
        int u, v; cin >> u >> v;
        links[u].push_back(v);
        links[v].push_back(u);
    }
    rep(i, 1, N+1) dfs(i, i, 0, 1);
    cout << st.size() << endl;
    // bool first = st.size()%2;
    // if(first) cout << "First" << endl;
    // else cout << "Second" << endl;

    // if(first){
    //     auto it = *st.begin();
    //     cout << it.first << " " << it.second << endl;
    //     st.erase(it);
    // }

    // while(1){
    //     pii oppo;
    //     cin >> oppo.first >> oppo.second;
    //     if(oppo.first == -1) break;
    //     st.erase({min(oppo.first, oppo.second), max(oppo.first, oppo.second)});
    //     auto it = *st.begin();
    //     cout << it.first << " " << it.second << endl;
    //     st.erase(it);
    // }
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