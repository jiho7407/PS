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

// Li-Chao Tree
// LiCT, LCT

const ll INF = 1e18;
struct LiChaoTree{
    // 구조체 정의
    struct Line{
        ll a, b;
        ll func(ll x){ return a*x + b; }
    };
    Line base = {0, -INF};
    struct Node{
        int l, r;
        ll s, e;
        Line line;
    };

    // 메인 트리
    vector<Node> tree;

    // 구간의 범위를 입력받아 초기화
    void init(ll s, ll e){
        tree.push_back({-1, -1, s, e, base});
    }

    void update(Line nl){ update(0, nl); }
    void update(int node, Line nl){
        ll s = tree[node].s, e = tree[node].e;
        ll m = (s+e)>>1;

        // 구간의 왼쪽 끝을 기준으로 high low 결정
        Line low = tree[node].line, high = nl;
        if(low.func(s) > high.func(s)) swap(low, high);

        // 구간의 오른쪽 끝을 기준으로 전체적으로 높은지 판단
        if(low.func(e) <= high.func(e)){ tree[node].line = high; return; }

        // 아니라면 중간값을 이용해 더 많은곳에서 높은 선 판단
        if(low.func(m) <= high.func(m)){
            tree[node].line = high;
            if(tree[node].r == -1){
                tree[node].r = tree.size();
                tree.push_back({-1, -1, m+1, e, {0, -INF}});
            }
            update(tree[node].r, low);
        }
        else{
            tree[node].line = low;
            if(tree[node].l == -1){
                tree[node].l = tree.size();
                tree.push_back({-1, -1, s, m, {0, -INF}});
            }
            update(tree[node].l, high);
        }
    }
    
    ll query(ll x){ return query(0, x); }
    ll query(int node, ll x){
        if (node == -1) return -INF;
        ll s = tree[node].s, e = tree[node].e;
        ll m = (s+e)>>1;
        if (x<=m) return max(tree[node].line.func(x), query(tree[node].l, x));
        else return max(tree[node].line.func(x), query(tree[node].r, x));
    }
}LiCT;

// Splay Tree
// ST

struct node{
    node *l, *r, *p;
    ll val, sz, sum;
    bool dummy;

    node(ll _val, node *_p): val(_val), p(_p){
        l = r = nullptr;
        sum = val;
        sz = 1;
        dummy = false;
    }

    node(ll _val) : node(_val, nullptr) {}

    node() : node(0) {}

    ~node(){
        if(l) delete l;
        if(r) delete r;
    }
};

struct SplayTree{
    node *root;
    node *ptr[1000110];

    SplayTree(): root(){
        fill(ptr, ptr+1000110, nullptr);
    }
    ~SplayTree(){
        if(root) delete root;
    }

    void init(int N){
        if(root) delete root;
        root = new node(-INF); // 왼쪽 더미
        node *cur = root;
        rep(i, 1, N+1){
            ptr[i] = cur->r = new node(arr[i], cur);
            cur = cur->r;
        }
        cur->r = new node(INF, cur); // 오른쪽 더미
        root->dummy = cur->r->dummy = true;
        for(int i = N; i >= 1; i--) update(ptr[i]);
        splay(ptr[(N+1)/2]);
    }

    void update(node *x){
        x->sz = 1;
        x->sum = x->val;
        if(x->l){
            x->sz += x->l->sz;
            x->sum += x->l->sum;
        }
        if(x->r){
            x->sz += x->r->sz;
            x->sum += x->r->sum;
        }
    }

    void rotate(node *x){
        node *p = x->p;
        node *tmp;
        if(x == p->l){
            tmp = p->l = x->r;
            x->r = p;
        }
        else{
            tmp = p->r = x->l;
            x->l = p;
        }
        x->p = p->p;
        p->p = x;

        if(tmp) tmp->p = p;

        if(x->p){
            if(p == x->p->l) x->p->l = x;
            else x->p->r = x;
        }
        else root = x;
        update(p);
        update(x);
    }

    void splay(node *x, node *goal = nullptr){
        node *y;
        while(x->p != goal){
            node *p = x->p;
            if(p->p == goal){
                rotate(x);
                break;
            }
            node *pp = p->p;
            if((p->l == x) == (pp->l == p)){
                rotate(p);
                rotate(x);
            }
            else{
                rotate(x);
                rotate(x);
            }
        }
        if(!goal) root = x;
    }

    // bool find(int key){
    //     node *cur = root;
    //     while(cur){
    //         if(key == cur->key) break;
    //         if(key < cur->key){
    //             if(!cur->l) break;
    //             cur = cur->l;
    //         }
    //         else{
    //             if(!cur->r) break;
    //             cur = cur->r;
    //         }
    //     }
    //     splay(cur);
    //     return key == cur->key;
    // }

    // void insert(int key, node *prv, node *&cur){
    //     if (!cur){
    //         cur = new node(key, prv);
    //         splay(cur);
    //         return;
    //     }
    //     if(key == cur->key) return; // 중복은 안돼!
    //     if(key < cur->key) insert(key, cur, cur->l);
    //     else insert(key, cur, cur->r);
    // }

    // void pop(int key){
    //     if(!find(key)) return;

    //     node *cur = root;
    //     if(cur->l && cur->r){
    //         root = cur->l; root->p = nullptr;

    //         node *tmp = root;
    //         while(tmp->r) tmp = tmp->r;
    //         tmp->r = cur->r;
    //         cur->r->p = tmp;
    //         splay(tmp);
    //     }
    //     else if(cur->l){
    //         root = cur->l;
    //         root->p = nullptr;
    //     }
    //     else if(cur->r){
    //         root = cur->r;
    //         root->p = nullptr;
    //     }
    //     else root = nullptr;
    //     delete cur;
    // }

    void kth(int k){
        node *cur = root;
        while(1){
            while(cur->l && cur->l->sz > k) cur = cur->l;
            if(cur->l) k -= cur->l->sz;
            if(!k--) break;
            cur = cur->r;
        }
        splay(cur);
    }

    node* gather(int s, int e){ // s-1 -> e+1이면 e+1의 왼쪽자식이 [s, e]
        kth(e+1);
        node *tmp = root;
        kth(s-1);
        splay(tmp, root);
        return root->r->l;
    }

    // void print(node *cur){
    //     cout << "cur: " << cur->key << " ";
    //     if(cur->l) cout << "l: " << cur->l->key << " ";
    //     if(cur->r) cout << "r: " << cur->r->key << " ";
    //     cout << "\n";
    //     if(!cur) return;
    //     if(cur->l) print(cur->l);
    //     cout << cur->key << " " << cur->cnt << "\n";
    //     if(cur->r) print(cur->r);
    // }

}ST;

// Link-Cut Tree
// LCT
struct Node{
    Node *l, *r, *p;
    int sz;
    ll val, sum;
    bool dummy, flip;
    Node(ll val, Node *p): val(val), p(p){
        l = r = nullptr;
        sz = 1;
        sum = val;
        dummy = flip = false;
    }
    Node(ll val): Node(val, nullptr){}
    Node(): Node(0, nullptr){}

    bool isRoot() { // 포레스트에서 루트인지 확인
        return p == nullptr || (p->l != this && p->r != this);
    }

    void rotate(){
        Node *tmp;
        if(p->l == this){
            tmp = p->l = r;
            r = p;
        }
        else{
            tmp = p->r = l;
            l = p;
        }
        if(tmp) tmp->p = p;

        if(!p->isRoot()) { // p의 조부모에서 지금 내가 왼/오
            if(p->p->l == p) p->p->l = this;
            else p->p->r = this;
        }
        tmp = p; p = p->p; tmp->p = this; // 조부모와 연결 관리
        tmp->update();
        update();
    }

    void update(){
        sz = 1; sum = val;
        if(l) sz += l->sz, sum += l->sum;
        if(r) sz += r->sz, sum += r->sum;
    }
    void update(ll val){
        this->val = val;
        update();
    }
    void push(){
        if(flip){
            flip = false;
            swap(l, r);
            if(l) l->flip ^= 1;
            if(r) r->flip ^= 1;
        }
    }
};

void Splay(Node *x){
    while(!x->isRoot()){
        Node *p = x->p;
        if(!p->isRoot()) p->p->push(); p->push(); x->push();
        if(!p->isRoot()){
            if((p->l == x) == (p->p->l == p)) p->rotate();
            else x->rotate();
        }
        x->rotate();
    }
    x->push();
}

Node* Access(Node *x){
    Splay(x); x->r = nullptr;
    x->update();

    Node *last = x;
    while(x->p){
        Node *tmp = x->p;
        last = tmp;
        Splay(tmp);
        tmp->r = x;
        tmp->update();
        Splay(x);
    }
    return last;
}

void Link(Node *p, Node *c){
    Access(c); Access(p);
    c->l = p; p->p = c;
    c->update();
}

void Cut(Node *x){
    Access(x);
    x->l->p = nullptr;
    x->l = nullptr;
    x->update();
}

void MakeRoot(Node *x){
    Access(x);
    Splay(x);
    x->flip ^= 1;
}

Node* FindRoot(Node *x){
    Access(x);
    while(x->l) x = x->l;
    Splay(x);
    return x;
}

Node* GetPar(Node *x){
    Access(x);
    if(!x->l) return nullptr;
    x = x->l;
    while(x->r) x = x->r;
    Splay(x);
    return x;
}

ll GetDepth(Node *x){
    Access(x);
    if(x->l) return x->l->sz;
    return 0;
}

Node* GetLCA(Node *x, Node *y){
    Access(x);
    return Access(y);
}

ll GetSum(Node *x, Node *y){
    Node *lca = GetLCA(x, y);
    ll ret = lca->val;
    Access(x); Splay(lca);
    if(lca->r) ret += lca->r->sum;

    Access(y); Splay(lca);
    if(lca->r) ret += lca->r->sum;

    return ret;
}

void Update(Node *x, ll val){
    Access(x);
    x->update(val);
}

int N, Q;
Node *ptr[30010];