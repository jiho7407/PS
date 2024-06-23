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


int N, M, K;
int A[250000];

struct SegmentTree2{
    vector<int> tree;
    int sz;

    void pull(int node){
        tree[node] = tree[node<<1] + tree[node<<1|1];
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
            if((left&1)==1) ret += tree[left++];
            if((right&1)==0) ret += tree[right--];
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST2;

struct SegmentTree1{
    vector<int> tree;
    int sz;

    void pull(int node){
        tree[node] = tree[node<<1]&tree[node<<1|1];
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

    void update(int l, int r, int x){
        update(1, 0, sz-1, l, r, x);
    }

    void update(int node, int s, int e, int qs, int qe, int x){
        if(qe < s || e < qs) return;
        if(qs <= s && e <= qe && (tree[node]&x) == x) return;
        if(s == e){
            if(tree[node] == K) ST2.update(s, -1);
            tree[node] |= x;
            if(tree[node] == K) ST2.update(s, 1);
            return;
        }
        int m = (s+e)>>1;
        update(node<<1, s, m, qs, qe, x);
        update(node<<1|1, m+1, e, qs, qe, x);
        pull(node);
        return;
    }
}ST1;

void solve(){
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    ST1.init(N);
    rep(i, 0, N) ST1.set(i, A[i]);
    ST1.build();
    ST2.init(N);
    rep(i, 0, N) ST2.set(i, (A[i] == K));
    ST2.build();
    cin >> M;
    while(M--){
        int op; cin >> op;
        if(op == 1){
            int l, r, x; cin >> l >> r >> x;
            l--, r--;
            ST1.update(l, r, x);
        }
        else{
            int l, r; cin >> l >> r;
            l--, r--;
            cout << ST2.query(l, r) << '\n';
        }
    }
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