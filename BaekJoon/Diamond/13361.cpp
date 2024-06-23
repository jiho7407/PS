#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

struct DSU{
    vector<int> par, sz;
    int cnt = 0;

    void init(int N){
        par.resize(N);
        sz.resize(N);
        for(int i = 0; i < N; i++){
            par[i] = i;
            sz[i] = 1;
        }
        cnt = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        cnt--;
    }
};

int N;
ll ans = 0;
vector<pll> board;
unordered_map<ll, int> mp2;

DSU dsu;
vector<int> idx[250000];
vector<ll> tmp;


void solve(){
    cin >> N;
    rep(i, 0, N){
        ll s, t;
        cin >> s >> t;
        ans += s + t;
        board.push_back({s, t});
    }

    dsu.init(N);
    rep(i, 0, N){
        auto [s, t] = board[i];
        if(mp2.find(s) == mp2.end()) mp2[s] = i;
        else{
            dsu.merge(i, mp2[s]);
        }
        if(mp2.find(t) == mp2.end()) mp2[t] = i;
        else{
            dsu.merge(i, mp2[t]);
        }
    }

    rep(i, 0, N){
        idx[dsu.find(i)].push_back(i);
    }

    rep(i, 0, N){
        if(idx[i].empty()) continue;
        tmp.clear();
        for(auto j : idx[i]){
            auto [s, t] = board[j];
            tmp.push_back(s);
            tmp.push_back(t);
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        rep(j, 0, dsu.sz[i]){
            ans -= tmp[j];
        }
    }
    
    cout << ans << '\n';
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