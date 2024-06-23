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
    int sz;
    Node *l, *r;
    Node(){
        sz = 0;
        l = r = nullptr;
    }

    Node(int sz): sz(sz), l(nullptr), r(nullptr){}
};

struct PersistentSegmentTree{
    Node *root[500001]; 

    void build(Node *node, int S, int E){
        if(S == E) return;
        int M = (S+E)>>1;
        node->l = new Node();
        node->r = new Node();
        build(node->l, S, M);
        build(node->r, M+1, E);
    }

    void update(int idx, int X, int V){
        root[idx] = new Node();
        update(root[idx-1], root[idx], 0, 524287, X, V);
    }

    void update(Node *prv, Node *cur, int S, int E, int X, int V){
        if(X < S || E < X) return;
        if(S == E){
            cur->sz = prv->sz + 1;
            return;
        }

        int M = (S+E)>>1;
        if(X <= M){
            cur->r = prv->r;
            cur->l = new Node(prv->l->sz + 1);
            update(prv->l, cur->l, S, M, X, V);
        }else{
            cur->l = prv->l;
            cur->r = new Node(prv->r->sz + 1);
            update(prv->r, cur->r, M+1, E, X, V);
        }
        cur->sz = cur->l->sz + cur->r->sz;
    }

    int query2(Node *prv, Node *cur, int S, int E, int X, int bit){
        if(S==E) return S;
        // cout << S << ' ' << E << ' ' << X << ' ' << bit << ' ' << cur->l->sz - prv->l->sz << ' ' << cur->r->sz - prv->r->sz << endl;
        int M = (S+E)>>1;
        if((X>>bit)&1){
            if(cur->l->sz - prv->l->sz) return query2(prv->l, cur->l, S, M, X, bit-1);
            else return query2(prv->r, cur->r, M+1, E, X, bit-1);
        }
        else{
            if(cur->r->sz - prv->r->sz) return query2(prv->r, cur->r, M+1, E, X, bit-1);
            else return query2(prv->l, cur->l, S, M, X, bit-1);
        }
    }

    int query4(Node *prv, Node *cur, int S, int E, int X){
        // cout << S << ' ' << E << ' ' << X << ' ' << cur->sz - prv->sz << endl;
        if(X < S) return 0;
        if(E <= X) return cur->sz - prv->sz;
        int M = (S+E)>>1;
        return query4(prv->l, cur->l, S, M, X) + query4(prv->r, cur->r, M+1, E, X);
    }

    int query5(Node *prv, Node *cur, int S, int E, int X){
        if(S == E) return S;
        int M = (S+E)>>1;
        int diff = cur->l->sz - prv->l->sz;
        if(X <= diff) return query5(prv->l, cur->l, S, M, X);
        else return query5(prv->r, cur->r, M+1, E, X-diff);
    }
};

int M;
PersistentSegmentTree PST;

void solve(){
    ifstream cin("D:\\Programming-D\\PS\\test\\input.txt");
    cin >> M;
    PST.root[0] = new Node();
    PST.build(PST.root[0], 0, 524287);
    int idx = 1;
    rep(i, 0, M){
        int op; cin >> op;
        if(op == 1) {
            int x; cin >> x;
            PST.update(idx, x, 1);
            idx++;
        }
        else if(op == 2){
            int L, R, x; cin >> L >> R >> x;
            cout << PST.query2(PST.root[L-1], PST.root[R], 0, 524287, x, 18) << '\n';
        }
        else if(op == 3){
            int x; cin >> x;
            idx -= x;
        }
        else if(op == 4){
            int L, R, x; cin >> L >> R >> x;
            cout << PST.query4(PST.root[L-1], PST.root[R], 0, 524287, x) << '\n';
        }
        else if(op == 5){
            int L, R, x; cin >> L >> R >> x;
            cout << PST.query5(PST.root[L-1], PST.root[R], 0, 524287, x) << '\n';
        }
        else assert(false);
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}