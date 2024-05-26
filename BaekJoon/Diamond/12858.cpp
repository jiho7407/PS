#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll gcd(ll a, ll b){
    if(a<0) a = -a;
    if(b<0) b = -b;
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

struct LazySegmentTree{
    vector<ll> tree, lazy;
    ll sz;

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, 0);
        lazy.assign(sz<<1, 0);
    }

    void pull(ll node){
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void push(ll node, ll start, ll end){
        if(lazy[node] != 0){
            tree[node] += (end - start + 1) * lazy[node];
            if(start != end){
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void set(ll idx, ll val){ tree[sz|idx] = val; }
    void build(){
        for(ll i = sz-1; i > 0; i--) pull(i);
    }
    
    void update(ll left, ll right, ll diff){
        update(1, 0, sz-1, left, right, diff);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, ll diff){
        push(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node] += diff;
            push(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        pull(node);
        return;
    }

    ll query(ll left, ll right){
        return query(1, 0, sz-1, left, right);
    }

    ll query(ll node, ll start, ll end, ll left, ll right){
        push(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        ll mid = (start + end)>>1;
        ll lq = query(node<<1, start, mid, left, right);
        ll rq = query(node<<1|1, mid+1, end, left, right);
        return lq + rq;
    }
};

struct SegmentTree{
    vector<int> tree;
    int sz;

    void pull(int node){
        tree[node] = gcd(tree[node<<1], tree[node<<1|1]);
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
        for(int i = sz-1; i > 0; i--) pull(i);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) pull(idx);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = gcd(ret, tree[left++]);
            if((right&1)==0) ret = gcd(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

int N, Q;
int A[100000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    LazySegmentTree LST(N);
    rep(i, 0, N) LST.set(i, A[i]);
    LST.build();
    SegmentTree ST;
    ST.init(N+1);
    rep(i, 1, N) ST.set(i, A[i]-A[i-1]);
    ST.set(N, 0);
    ST.build();
    cin >> Q;
    while(Q--){
        int q, a, b;
        cin >> q >> a >> b; a--; b--;
        if(q==0){
            cout << gcd(LST.query(a, a), ST.query(a+1, b)) << '\n';
        }
        else{
            LST.update(a, b, q);
            ST.update(a, q);
            ST.update(b+1, -q);
        }
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}