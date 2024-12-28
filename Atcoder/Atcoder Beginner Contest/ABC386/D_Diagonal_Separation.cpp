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

// Segment Tree
struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return a+b;
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

void solve(){
    ll N, M;
    cin >> N >> M;

    vector<tuple<int, int, string>> v;
    vector<int> xs, ys;
    rep(i, 0, M){
        int X, Y; string C;
        cin >> X >> Y >> C;
        v.push_back({X, Y, C});
        xs.push_back(X);
        ys.push_back(Y);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    rep(i, 0, M){
        auto [X, Y, C] = v[i];
        int x = lower_bound(xs.begin(), xs.end(), X) - xs.begin();
        int y = lower_bound(ys.begin(), ys.end(), Y) - ys.begin();
        v[i] = {x, y, C};
    }
    sort(v.begin(), v.end());

    int sz = ys.size();
    ST.init(sz);
    rep(i, 0, M){
        auto [X, Y, C] = v[i];
        if(C == "B") ST.update(Y, 1);
    }

    bool ans = true;
    rep(i, 0, M){
        auto [X, Y, C] = v[i];
        if(C == "W"){
            if(ST.query(Y, sz-1) > 0) ans = false;
        }
        else{
            ST.update(Y, -1);
        }
    }

    if(ans) cout << "Yes";
    else cout << "No";
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