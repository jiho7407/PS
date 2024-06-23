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

void solve(){
    cin >> N;
    rep(i, 1, N+1){
        ll val;
        cin >> val;
        ptr[i] = new Node(val);
    }
    cin >> Q;
    while(Q--){
        string op; ll a, b;
        cin >> op >> a >> b;
        if(op == "bridge"){
            if(FindRoot(ptr[a]) == FindRoot(ptr[b])) cout << "no" << endl;
            else{
                cout << "yes" << endl;
                MakeRoot(ptr[a]);
                MakeRoot(ptr[b]);
                Link(ptr[a], ptr[b]);
            }
        }
        else if(op == "penguins"){
            Update(ptr[a], b);
        }
        else{
            if(FindRoot(ptr[a]) != FindRoot(ptr[b])) cout << "impossible" << endl;
            else cout << GetSum(ptr[a], ptr[b]) << endl;
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