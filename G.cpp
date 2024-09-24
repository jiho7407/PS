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

struct Fenwick2D{
    int N, M;
    vector<unordered_map<int, int>> tree;
    void init(int n, int m){
        tree.assign(n+1, unordered_map<int, int>());
        N = n+1;
        M = m+1;
    }
    void update(int x, int y, int diff){
        // cout << "update " << x << ' ' << y << ' ' << diff << '\n';
        for(int i = x; i < N; i += (i & -i)){
            for(int j = y; j < M; j += (j & -j)){
                if(tree[i].find(j) == tree[i].end()) tree[i][j] = 1e9;
                tree[i][j] = min(tree[i][j], diff);
            }
        }
    }
    int query(int x, int y){
        int ret = 1e9;
        for(int i = x; i > 0; i -= (i & -i)){
            for(int j = y; j > 0; j -= (j & -j)){
                if(tree[i].find(j) == tree[i].end()) continue;
                ret = min(ret, tree[i][j]);
            }
        }
        // cout << "query " << x << ' ' << y << ' ' << ret << '\n';
        return ret;
    }
}FT;

int N;
short A[100000];
vector<int> pfsum[4];

void calc(){
    int ans = 0;

    vector<tuple<int, int, int>> points[100001];
    vector<int> xs, ys, zs;
    rep(i, 0, N+1){
        int a = pfsum[0][i];
        int b = pfsum[1][i];
        int c = pfsum[2][i];
        int d = pfsum[3][i];
        xs.push_back(a-b);
        ys.push_back(a-c);
        zs.push_back(a-d);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());
    rep(i, 0, N+1){
        int a = pfsum[0][i];
        int b = pfsum[1][i];
        int c = pfsum[2][i];
        int d = pfsum[3][i];
        int na = lower_bound(xs.begin(), xs.end(), a-b) - xs.begin();
        int nb = lower_bound(ys.begin(), ys.end(), a-c) - ys.begin();
        int nc = lower_bound(zs.begin(), zs.end(), a-d) - zs.begin();
        // cout << na << ' ' << nb << ' ' << nc << '\n';
        points[na].emplace_back(nb+1, nc+1, i);
    }

    FT.init(ys.size(), zs.size());
    rep(i, 0, xs.size()){
        for(auto [y, z, idx]: points[i]){
            ans = max(ans, idx - FT.query(y, z));
        }
        for(auto [y, z, idx]: points[i]){
            FT.update(y+1, z+1, idx);
        }
    }

    cout << ans << ' ';
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, 4) pfsum[i].push_back(0);
    rep(i, 0, N) rep(j, 0, 4) pfsum[j].push_back(pfsum[j].back() + (A[i] == j));

    calc();
    swap(pfsum[0], pfsum[1]);
    calc();
    swap(pfsum[0], pfsum[2]);
    calc();
    swap(pfsum[0], pfsum[3]);
    calc();
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