// Segment Tree

struct SegmentTree{
    int tree[2100];
    int sz;
    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
    }
    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = tree[idx<<1] + tree[idx<<1|1];
        }
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
};

struct SegmentTree2D{
    SegmentTree ST[2100];
    int sz;
    void init(int N, int M){
        sz = 1;
        while(sz < N) sz <<= 1;
        for(int i = 0; i < 2*sz; i++) ST[i].init(M);
    }
    void update(int i, int j, int x){
        int idx = sz + i;
        ST[idx].update(j, x);
        while(idx >>= 1){
            int q1 = ST[idx<<1].query(j, j);
            int q2 = ST[idx<<1|1].query(j, j);
            ST[idx].update(j, q1 + q2);
        }
    }
    int query(int L, int R, int U, int D){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1) == 1) ret += ST[left++].query(U, D);
            if((right&1) == 0) ret += ST[right--].query(U, D);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

// Segment Tree
// 초기 업데이트시간 O(NlogN) -> O(N), vector 사용버전
struct SegmentTree{
    vector<int> tree;
    int sz;
    void init(int N, vector<int>& lst){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
        for(int i = 0; i < N; i++){
            tree[sz+i] = lst[i];
        }
        for(int i = sz-1; i > 0; i--){
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
        }
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++]);
            if((right&1)==0) ret = max(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

struct SegmentTree2D{
    vector<SegmentTree> ST;
    int sz;
    void init(int N, int M, vector<vector<int>>& lst){
        sz = 1;
        while(sz < N) sz <<= 1;
        ST.resize(2*sz);
        for(int i = 0; i<N; i++){
            ST[sz+i].init(M, lst[i]);
        }
        vector<int> tmp(M, 0);
        for(int i = N; i<sz; i++){
            ST[sz+i].init(M, tmp);
        }
        for(int i = sz-1; i > 0; i--){
            ST[i].init(M, tmp);
            for(int j = 0; j < M; j++){
                int q1 = ST[i<<1].query(j, j);
                int q2 = ST[i<<1|1].query(j, j);
                ST[i].update(j, max(q1, q2));
            }
        }
    }
    void update(int i, int j, int x){
        int idx = sz + i;
        ST[idx].update(j, x);
        while(idx >>= 1){
            int q1 = ST[idx<<1].query(j, j);
            int q2 = ST[idx<<1|1].query(j, j);
            ST[idx].update(j, max(q1, q2));
        }
    }
    int query(int L, int R, int U, int D){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1) == 1) ret = max(ret, ST[left++].query(U, D));
            if((right&1) == 0) ret = max(ret, ST[right--].query(U, D));
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};



// Fenwick Tree
// 펜윅트리는 1기반 인덱싱. 0 넣지 않게 조심

struct Fenwick{
    vector<ll> tree;
    Fenwick(int n){
        tree.resize(n+1);
    }
    void update(int idx, ll diff){
        while(idx < tree.size()){
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
    ll query(int idx){
        ll ret = 0;
        while(idx > 0){
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
};

struct Fenwick2D{
    vector<vector<ll>> tree;
    Fenwick2D(int n, int m){
        tree.resize(n+1, vector<ll>(m+1));
    }
    void update(int x, int y, ll diff){
        for(int i = x; i < tree.size(); i += (i & -i)){
            for(int j = y; j < tree[i].size(); j += (j & -j)){
                tree[i][j] += diff;
            }
        }
    }
    ll query(int x, int y){
        ll ret = 0;
        for(int i = x; i > 0; i -= (i & -i)){
            for(int j = y; j > 0; j -= (j & -j)){
                ret += tree[i][j];
            }
        }
        return ret;
    }
};

// Lazy Segment Tree, Lazy Propagation
// 구간 업데이트, 구간 쿼리

struct LazySegmentTree{
    vector<ll> tree, lazy;
    ll sz;

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, 0);
        lazy.assign(sz<<1, 0);
    }

    void set(ll idx, ll val){ tree[sz|idx] = val; }
    void build(){
        for(ll i = sz-1; i > 0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];
    }

    void propagate(ll node, ll start, ll end){
        if(lazy[node] != 0){
            tree[node] += (end - start + 1) * lazy[node];
            if(start != end){
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(ll left, ll right, ll diff){
        update(1, 0, sz-1, left, right, diff);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, ll diff){
        propagate(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            tree[node] += (end - start + 1) * diff;
            if(start != end){
                lazy[node<<1] += diff;
                lazy[node<<1|1] += diff;
            }
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        tree[node] = tree[node<<1] + tree[node<<1|1];
        return;
    }

    ll query(ll left, ll right){
        return query(1, 0, sz-1, left, right);
    }

    ll query(ll node, ll start, ll end, ll left, ll right){
        propagate(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        ll mid = (start + end)>>1;
        return query(node<<1, start, mid, left, right) + query(node<<1|1, mid+1, end, left, right);
    }
};