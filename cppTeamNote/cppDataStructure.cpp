// Segment Tree
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
    void build(){ for(ll i = sz-1; i > 0; i--) pull(i); }
    
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

// Persistent Segment Tree
// PST

struct Node{
    Node *L, *R;
    ll V;
    Node(){ L = R = nullptr; V = 0; }
};

struct PersistentSegmentTree{
    Node *root[200001]; // root[i]: i번째 버전의 루트 노드

    void build(Node *node, int S, int E){
        if(S == E){ node->V = 0; return; }
        int M = (S+E)>>1;
        node->L = new Node();
        node->R = new Node();
        build(node->L, S, M);
        build(node->R, M+1, E);
        node->V = node->L->V + node->R->V;
    }

    void update(int prev, int cur, int X, int V){
        update(root[prev], root[cur], 0, N-1, X, V);
    }

    void update(Node *prev, Node *cur, int S, int E, int X, int V){
        if(X<S || X>E) return;
        if(S==E){ cur->V = V; return; }
        int M = (S+E)>>1;
        if(X<=M){
            cur->L = new Node();
            cur->R = prev->R;
            update(prev->L, cur->L, S, M, X, V);
        }
        else{
            cur->L = prev->L;
            cur->R = new Node();
            update(prev->R, cur->R, M+1, E, X, V);
        }
        cur->V = cur->L->V + cur->R->V;
    }

    ll query(int prev, int cur, int K){
        return query(root[prev], root[cur], 0, N-1, K);
    }

    ll query(Node *prev, Node *cur, int S, int E, int K){
        if(S == E) return S;
        int DIFF = cur->L->V - prev->L->V;
        int M = (S+E)>>1;
        if(K <= DIFF) return query(prev->L, cur->L, S, M, K);
        else return query(prev->R, cur->R, M+1, E, K-DIFF);
    }
}PST;