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
    Node(): sz(0), l(nullptr), r(nullptr){}
    Node(int sz): sz(sz), l(nullptr), r(nullptr){}

    ~Node(){
        if(l) delete l;
        if(r) delete r;
    }
};

void build(Node *node, int S, int E){
    if(S == E) return;
    int M = (S+E)>>1;
    node->l = new Node();
    node->r = new Node();
    build(node->l, S, M);
    build(node->r, M+1, E);
}

void update(Node *prv, Node *cur, int S, int E, int idx){
    if(idx < S || E < idx) return;
    if(S == E){
        cur->sz = prv->sz + 1;
        return;
    }

    int M = (S+E)>>1;
    if(idx <= M){
        cur->r = prv->r;
        cur->l = new Node(prv->l->sz + 1);
        update(prv->l, cur->l, S, M, idx);
    }
    else{
        cur->l = prv->l;
        cur->r = new Node(prv->r->sz + 1);
        update(prv->r, cur->r, M+1, E, idx);
    }
    cur->sz = cur->l->sz + cur->r->sz;
}

int query(Node *prv, Node *cur, int S, int E, int qs, int qe){
    if(E < qs || qe < S) return 0;
    if(qs <= S && E <= qe) return cur->sz - prv->sz;
    int M = (S+E)>>1;
    int lq = query(prv->l, cur->l, S, M, qs, qe);
    int rq = query(prv->r, cur->r, M+1, E, qs, qe);
    return lq+rq;
}

int N, M;
vector<int> eggs[100002];
Node *root[100002];

void solve(){
    cin >> N >> M;
    rep(i, 0, N){
        int x, y; cin >> x >> y;
        x++; y++;
        eggs[x].push_back(y);
    }

    root[0] = new Node();
    build(root[0], 0, 100001);
    rep(i, 1, 100002){
        Node *prv = root[i-1];
        for(auto y: eggs[i]){
            // cout << "add " << i << ' ' << y << '\n';
            Node *cur = new Node();
            update(prv, cur, 0, 100001, y);
            prv = cur;
        }
        root[i] = prv;
    }

    ll ans = 0;
    while(M--){
        int l, r, b, t; cin >> l >> r >> b >> t;
        l++, r++, b++, t++;
        ans += query(root[l-1], root[r], 0, 100001, b, t);
    }
    cout << ans << '\n';
    // cout << query(root[0], root[100001], 0, 100001, 0, 100001);
    rep(i, 0, 100001) eggs[i].clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}