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

const ll INF = 1e18;
ll arr[1000110];

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

int N, M, K;

void solve(){
    cin >> N >> M >> K;
    rep(i, 1, N+1) cin >> arr[i];
    ST.init(N);
    rep(i, 0, M+K){
        ll op, a, b; cin >> op >> a >> b;
        if(op==1){
            ST.kth(a);
            ST.root->val = b;
            ST.update(ST.root);
        }
        else{
            cout << ST.gather(a, b)->sum << "\n";
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