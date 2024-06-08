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

struct Node{
    Node *l, *r, *p;
    ll val, sz;
    bool dummy, reverse;

    int pf, sf, mf;

    Node(ll _val, Node *_p): val(_val), p(_p){
        l = r = nullptr;
        sz = 1;
        dummy = reverse = false;
        if(val == 1) pf = sf = mf = 1;
        else pf = sf = mf = 0;
    }

    Node(ll _val) : Node(_val, nullptr) {}
    Node() : Node(0) {}
    ~Node(){
        if(l) delete l;
        if(r) delete r;
    }
};

struct SplayTree{
    static const int mxN = 300100;
    static const ll INF = 1e18;
    Node *root;
    Node *ptr[mxN];

    SplayTree(): root(){
        fill(ptr, ptr+mxN, nullptr);
    }
    ~SplayTree(){
        if(root) delete root;
    }

    void init(int N, vector<ll> &arr){
        if(root) delete root;
        root = new Node(-INF); // 왼쪽 더미
        root->dummy = true;
        Node *cur = root;
        rep(i, 1, N+1){
            ptr[i] = cur->r = new Node(arr[i], cur);
            cur = cur->r;
        }
        cur->r = new Node(INF, cur);
        cur->r->dummy = true;
        for(int i = N; i >= 1; i--) update(ptr[i]);
    }

    void push(Node *x){
        if(x->reverse){
            swap(x->l, x->r);
            swap(x->pf, x->sf);
            if(x->l) x->l->reverse ^= 1;
            if(x->r) x->r->reverse ^= 1;
            x->reverse = false;
        }
    }
    
    void update(Node *x){
        push(x);
        x->sz = 1;
        if(x->l) { push(x->l); x->sz += x->l->sz; }
        if(x->r) { push(x->r); x->sz += x->r->sz; }

        x->pf = x->sf = x->mf = (x->val == 1);

        if(x->val == 1){
            if(x->l && x->r){
                if(x->l->pf == x->l->sz) x->pf = x->l->sz + 1 + x->r->pf;
                else x->pf = x->l->pf;
                if(x->r->sf == x->r->sz) x->sf = x->r->sz + 1 + x->l->sf;
                else x->sf = x->r->sf;
                x->mf = max({x->l->mf, x->r->mf, x->l->sf + x->r->pf + 1});
            }
            else if(x->l){
                if(x->l->pf == x->l->sz) x->pf = x->l->sz + 1;
                else x->pf = x->l->pf;
                x->sf = x->l->sf + 1;
                x->mf = max(x->l->mf, x->l->sf + 1);
            }
            else if(x->r){
                x->pf = 1+x->r->pf;
                if(x->r->sf == x->r->sz) x->sf = x->r->sz + 1;
                else x->sf = x->r->sf;
                x->mf = max(x->r->mf, 1+x->r->pf);
            }
        }
        else{
            if(x->l){
                x->pf = x->l->pf;
                x->mf = max(x->mf, x->l->mf);
            }
            if(x->r){
                x->sf = x->r->sf;
                x->mf = max(x->mf, x->r->mf);
            }
        }
    }

    void rotate(Node *x){
        Node *p = x->p;
        Node *tmp;
        push(p); push(x);
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
        update(p); update(x);
    }

    void splay(Node *x, Node *g = nullptr){
        while(x->p != g){
            Node *p = x->p;
            Node *pp = p->p;
            if(pp != g){
                if((pp->l == p) == (p->l == x)) rotate(p);
                else rotate(x);
            }
            rotate(x);
        }
        if(!g) root = x;
    }

    void kth(ll k){
        Node *cur = root;
        push(cur);
        while(1){
            while(cur->l && cur->l->sz > k){ cur = cur->l; push(cur); }
            if(cur->l) k -= cur->l->sz;
            if(!k--) break;
            cur = cur->r;
            push(cur);
        }
        splay(cur);
    }

    Node *gather(ll s, ll e){
        kth(e+1);
        Node *tmp = root;
        kth(s-1);
        splay(tmp, root);
        return root->r->l;
    }

    void reverse(ll s, ll e){
        Node *x = gather(s, e);
        // cout << root->val << " " << root->r->val << "\n";
        x->reverse ^= 1;
        while(x->p){
            update(x);
            x = x->p;
        }
    }

    void PRINT(Node *x){
        if(x->l) {
            // cout << "left ";
            PRINT(x->l);
        }
        if(!x->dummy) cout << x->val << ' ';
        // cout << x->val << ' ' << x->pf << ' ' << x->sf << ' ' << x->mf << '\n';
        if(x->r){
            // cout << "right ";
            PRINT(x->r);
        }
    }
}ST;

int N, M;
vector<ll> arr;

void solve(){
    cin >> N;
    arr.resize(N+1);
    rep(i, 1, N+1) cin >> arr[i];
    ST.init(N, arr);
    // ST.PRINT(ST.root);
    // cout << '\n';
    // ST.reverse(3, 4);
    // ST.PRINT(ST.root);
    // cout << '\n';

    cin >> M;
    while(M--){
        int op, l, r; cin >> op >> l >> r;
        if(op == 1) ST.reverse(l, r);
        else{
            auto tmp = ST.gather(l, r);
            cout << tmp->mf << "\n";
        }
        // ST.PRINT(ST.root);
        // cout << endl;
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