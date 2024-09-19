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
        tree.assign(sz<<1, 0);
        rep(i, 0, N) tree[sz+i] = 1;
        build();
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int idx, int val){
        idx += sz;
        while(idx){
            tree[idx] += val;
            idx >>= 1;
        }
    }

    int Kth(int k){ // kth 1-based
        return Kth(1, 0, sz-1, k);
    }

    int Kth(int idx, int ns, int ne, int k){
        if(ns == ne) return ns;
        int mid = (ns+ne)/2;
        if(tree[idx<<1] >= k) return Kth(idx<<1, ns, mid, k);
        return Kth(idx<<1|1, mid+1, ne, k-tree[idx<<1]);
    }
}ST;

int N, Q;
vector<pll> W;
vector<ll> pfsum;
tuple<int, int, int> query[100000]; // block, remain, idx

void solve(){
    W.clear();
    pfsum.clear();

    cin >> N >> Q;
    rep(i, 0, N){
        ll w; cin >> w;
        W.push_back({w, i});
    }
    sort(W.begin(), W.end());
    pfsum.assign(N+1, 0);
    pfsum[1] = N*W[0].first;
    rep(i, 1, N){
        pfsum[i+1] = pfsum[i] + (N-i)*(W[i].first-W[i-1].first);
    }
    
    rep(i, 0, Q){
        ll X; cin >> X; X--;
        ll block = upper_bound(pfsum.begin(), pfsum.end(), X) - pfsum.begin() - 1;
        ll idx = (X - pfsum[block]) % (N-block);
        query[i] = {block, idx, i};
    }

    sort(query, query+Q);
    ST.init(N);
    int bidx = 0;
    ll ans = 0;

    rep(i, 0, Q){
        auto [block, idx, qidx] = query[i];
        while(bidx < block){
            ST.update(W[bidx].second, -1);
            bidx++;
        }
        ans += ST.Kth(idx+1)+1;
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}