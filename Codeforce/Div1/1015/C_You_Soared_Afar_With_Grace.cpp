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

void solve(){
    int N; cin >> N;
    vector<int> A(N), B(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    vector<pii> v(N);
    rep(i, 0, N) v[i] = {A[i], B[i]};
    set<pii> st;
    rep(i, 0, N) st.insert(v[i]);
    int scnt = 0;
    rep(i, 0, N){
        auto [a, b] = v[i];
        if(a == b) scnt++;
        if(st.find({b, a}) == st.end()){
            cout << -1 << '\n';
            return;
        }
    }
    if(scnt >= 2 || (scnt == 1 && N%2 == 0)){
        cout << -1 << '\n';
        return;
    }
    map<pii, int> mp;
    rep(i, 0, N) mp[v[i]] = i;
    vector<int> idxs(N, -1);
    int idx = 0;
    rep(i, 0, N){
        if(idxs[i] != -1) continue;
        auto [a, b] = v[i];
        if(a == b){
            idxs[i] = N/2;
            continue;
        }
        idxs[i] = idx;
        idxs[mp[{b, a}]] = N-1-idx;
        idx++;
    }

    // delete cycles
    vector<pii> ans;
    vector<bool> vis(N, false);
    rep(i, 0, N){
        if(vis[i]) continue;
        vector<int> cycle;
        int cur = i;
        while(!vis[cur]){
            vis[cur] = true;
            cycle.push_back(cur);
            cur = idxs[cur];
        }
        if(cycle.size() == 1) continue;
        cycle.push_back(cycle[0]);
        int sz = cycle.size();
        for(int i = sz-1; i>1; i--) ans.push_back({cycle[i-1], cycle[i]});
    }
    cout << ans.size() << '\n';
    for(auto [a, b]: ans) cout << a+1 << ' ' << b+1 << '\n';
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