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