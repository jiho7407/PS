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
vector<tuple<int, int, int>> edges;

struct UnionFind{
    vector<int> par, cnt;
    int group;

    void init(int N){
        par.resize(N);
        cnt.resize(N);
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
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
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
    }
}UF;

void solve(){
    cin >> N >> M;
    while(M--){
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        edges.push_back({w, a, b});
    }
    sort(edges.begin(), edges.end());

    UF.init(N);
    int ans = 0;
    for(auto [w, a, b]: edges){
        if(UF.find(a) == UF.find(b)) continue;
        UF.merge(a, b);
        ans += w;
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