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

const ll mxN = 300100;
const ll INF = 1e18;
ll arr[mxN];

struct node{
    node *l, *r, *p;
    ll val, sz;
    ll mn, mx, sum;
    bool dummy, reverse;

    node(ll _val, node *_p): val(_val), p(_p){
        l = r = nullptr;
        sz = 1;
        mn = mx = sum = val;
        dummy = reverse = false;
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
    node *ptr[mxN];

    SplayTree(): root(){
        fill(ptr, ptr+mxN, nullptr);
    }
    ~SplayTree(){
        if(root) delete root;
    }

    void init(ll N){
        if(root) delete root;
        root = new node(-INF); // 왼쪽 더미
        node *cur = root;
        rep(i, 1, N+1){
            ptr[i] = cur->r = new node(arr[i], cur);
            cur = cur->r;
        }
        cur->r = new node(INF, cur); // 오른쪽 더미
        root->dummy = cur->r->dummy = true;
        for(ll i = N; i >= 1; i--) update(ptr[i]);
        splay(ptr[(N+1)/2]);
    }

    void push(node *x){
        if(!x->reverse) return;
        swap(x->l, x->r);
        if(x->l) x->l->reverse ^= 1;
        if(x->r) x->r->reverse ^= 1;
        x->reverse = 0;
    }

    void update(node *x){
        x->sz = 1;
        x->mn = x->mx = x->sum = x->val;
        if(x->l){
            x->sz += x->l->sz;
            x->mn = min(x->mn, x->l->mn);
            x->mx = max(x->mx, x->l->mx);
            x->sum += x->l->sum;
        }
        if(x->r){
            x->sz += x->r->sz;
            x->mn = min(x->mn, x->r->mn);
            x->mx = max(x->mx, x->r->mx);
            x->sum += x->r->sum;
        }
    }

    void rotate(node *x){
        node *p = x->p;
        node *tmp;
        push(p);
        push(x);
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

    void kth(ll k){
        node *cur = root;
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

    node* gather(ll s, ll e){ // s-1 -> e+1이면 e+1의 왼쪽자식이 [s, e]
        kth(e+1);
        node *tmp = root;
        kth(s-1);
        splay(tmp, root);
        return root->r->l;
    }

    void reverse(ll s, ll e){
        node *tmp = gather(s, e);
        tmp->reverse ^= 1;
    }
    
    void print(node *cur){
        if(!cur) return;
        push(cur);
        print(cur->l);
        if(!cur->dummy) cout << cur->val << ' ';
        print(cur->r);
    }
}ST;

ll N, Q;

void solve(){
    cin >> N >> Q;
    rep(i, 1, N+1) arr[i] = i;
    ST.init(N);
    while(Q--){
        ll op; cin >> op;
        if(op == 1){
            ll s, e; cin >> s >> e;
            node *tmp = ST.gather(s, e);
            cout << tmp->mn << ' ' << tmp->mx << ' ' << tmp->sum << '\n';
            ST.reverse(s, e);
        }
        else if(op == 2){
            ll s, e, k; cin >> s >> e >> k;
            node *tmp = ST.gather(s, e);
            cout << tmp->mn << ' ' << tmp->mx << ' ' << tmp->sum << '\n';
            if(s==e) continue;
            if(k < 0){
                k *= -1;
                k %= (e-s+1);
                if(k == 0) continue;
                ST.reverse(s, s+k-1);
                ST.reverse(s+k, e);
                ST.reverse(s, e);
            }
            else{
                k %= (e-s+1);
                if(k == 0) continue;
                ST.reverse(e-k+1, e);
                ST.reverse(s, e-k);
                ST.reverse(s, e);
            }
        }
        else if(op == 3){
            ll k; cin >> k;
            ST.kth(k);
            cout << ST.root->val << '\n';
        }
        else{
            ll k; cin >> k;
            ST.splay(ST.ptr[k]);
            cout << ST.root->l->sz << '\n';
        }
    }
    ST.print(ST.root);
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