/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Node{
    ll sum, pf, sf, mx;
    Node(int x = -1e9){
        sum = pf = sf = mx = x;
    }
};

struct SegmentTree{
    vector<Node> tree;
    int sz;

    Node pull(Node a, Node b){
        Node ret;
        ret.sum = a.sum + b.sum;
        ret.pf = max(a.pf, a.sum + b.pf);
        ret.sf = max(b.sf, b.sum + a.sf);
        ret.mx = max({a.mx, b.mx, a.sf + b.pf});
        return ret;
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }

    void clear(){
        rep(i, 0, 2*sz) tree[i] = Node();
    }
    
    void set(int i, int x){
        tree[sz+i] = Node(x);
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = Node(x);
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        Node retL, retR;
        while(left <= right){
            if((left&1)==1) retL = pull(retL, tree[left++]);
            if((right&1)==0) retR = pull(tree[right--], retR);
            left >>= 1; right >>= 1;
        }
        return pull(retL, retR).mx;
    }
}ST;

int N, Q, mxh;
vector<pii> A;
int ok[100000], ng[100000];
tuple<int, int, int> query[100000];
int ans[100000];

void solve(){
    cin >> N;
    rep(i, 0, N){
        int x; cin >> x;
        A.pb({x, i});
        mxh = max(mxh, x);
    }
    sort(all(A), [](pii a, pii b){
        return a.first > b.first;
    });
    ST.init(N);
    
    cin >> Q;
    rep(i, 0, Q){
        int l, r, w; cin >> l >> r >> w;
        l--; r--;
        query[i] = {w, l, r};
        ok[i] = 1; ng[i] = mxh + 1;
    }

    while(1){
        bool flag = false;
        vector<pii> pbs;
        rep(i, 0, Q){
            if(ng[i] - ok[i] <= 1) continue;
            pbs.pb({(ok[i] + ng[i]) >> 1, i});
            flag = true;
        }
        if(!flag) break;
        ST.clear();
        sort(all(pbs), [](pii a, pii b){
            return a.first > b.first;
        });
        int idx = 0;
        for(auto [x, i]: pbs){
            auto [w, l, r] = query[i];
            while(idx < N && A[idx].first >= x){
                ST.update(A[idx].second, 1);
                idx++;
            }
            int mx = ST.query(l, r);
            if(mx >= w) ok[i] = x;
            else ng[i] = x;
            // rep(i, 0, N) cout << ST.query(i, i) << ' ';
            // cout << '\n';
            // cout << ST.query(0, N-1) << ' ' << idx  << ' ' << x << endl;
        }
    }

    rep(i, 0, Q) cout << ok[i] << '\n';
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