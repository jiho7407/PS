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

    Node(ll _val, Node *_p): val(_val), p(_p){
        l = r = nullptr;
        sz = 1;
        dummy = reverse = false;
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
    }

    void push(Node *x){
        if(x->reverse){
            swap(x->l, x->r);
            if(x->l) x->l->reverse ^= 1;
            if(x->r) x->r->reverse ^= 1;
            x->reverse = false;
        }
    }
    
    void update(Node *x){
        x->sz = 1;
        if(x->l) x->sz += x->l->sz;
        if(x->r) x->sz += x->r->sz;
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
        x->reverse ^= 1;
    }

    void PRINT(Node *x){
        if(x->l) PRINT(x->l);
        if(!x->dummy) cout << x->val << ' ';
        if(x->r) PRINT(x->r);
    }
}ST;


void solve(){
    while(1){
        int N; cin >> N;
        if(N == 0) return;
        vector<ll> arr(N+1);
        rep(i, 1, N+1) cin >> arr[i];
        ST.init(N, arr);

        vector<pii> idx;
        rep(i, 1, N+1){
            idx.push_back({arr[i], i});
        }
        sort(idx.begin(), idx.end());
        rep(i, 0, N){
            ST.splay(ST.ptr[idx[i].second]);
            // cout << "reversed " << i << " to " << ST.root->l->sz << '\n';
            cout << ST.root->l->sz << ' ';
            ST.reverse(i+1, ST.root->l->sz);
            // ST.PRINT(ST.root);
            // cout << '\n';
        }
        cout << '\n';
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