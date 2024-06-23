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

ll addmod(ll a, ll b, ll mod){
    return (a%mod + b%mod)%mod;
}

ll mulmod(ll a, ll b, ll mod){
    return (a%mod * b%mod)%mod;
}

ll mod = 998244353;
struct Node{
    ll A, B, mul;

    Node(ll a = 0, ll b = 0, ll m = 0): A(a), B(b), mul(m) {}
};

struct LazySegmentTree{
    vector<Node> tree;
    vector<pll> lazy; // a, b
    ll sz;

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz<<1);
        lazy.resize(sz<<1);
    }

    Node pull(Node a, Node b){
        return Node(addmod(a.A, b.A, mod), addmod(a.B, b.B, mod), addmod(a.mul, b.mul, mod)); 
    }

    void push(ll node, ll start, ll end){
        if(lazy[node] == pll(0, 0)) return;
        // cout << "pushing " << node << ' ' << start << ' ' << end << ' ' << lazy[node].first << ' ' << lazy[node].second << '\n';
        ll ap = lazy[node].first, bp = lazy[node].second;
        tree[node].mul = addmod(tree[node].mul, mulmod(ap, tree[node].B, mod), mod);
        tree[node].mul = addmod(tree[node].mul, mulmod(bp, tree[node].A, mod), mod);
        ll tmp = mulmod(ap, bp, mod);
        tmp = mulmod(tmp, end-start+1, mod);
        tree[node].mul = addmod(tree[node].mul, tmp, mod);

        tree[node].A = addmod(tree[node].A, mulmod(ap, (end-start+1), mod), mod);
        tree[node].B = addmod(tree[node].B, mulmod(bp, (end-start+1), mod), mod);

        if(start != end){
            lazy[node<<1].first = addmod(lazy[node<<1].first, ap, mod);
            lazy[node<<1].second = addmod(lazy[node<<1].second, bp, mod);
            lazy[node<<1|1].first = addmod(lazy[node<<1|1].first, ap, mod);
            lazy[node<<1|1].second = addmod(lazy[node<<1|1].second, bp, mod);
        }
        lazy[node] = pll(0, 0);
    }

    void set(ll idx, ll A, ll B){ tree[sz|idx] = Node(A, B, mulmod(A, B, mod)); }
    void build(){ for(ll i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]); }
    
    void update(ll left, ll right, pll diff){
        update(1, 0, sz-1, left, right, diff);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, pll diff){
        push(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node] = diff;
            push(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        tree[node] = pull(tree[node<<1], tree[node<<1|1]);
        return;
    }

    Node query(ll left, ll right){
        return query(1, 0, sz-1, left, right);
    }

    Node query(ll node, ll start, ll end, ll left, ll right){
        push(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        ll mid = (start + end)>>1;
        Node lq = query(node<<1, start, mid, left, right);
        Node rq = query(node<<1|1, mid+1, end, left, right);
        return pull(lq, rq);
    }
};

const int mxN = 2e5;
int N, Q;
ll A[mxN], B[mxN];

void solve(){
    cin >> N >> Q;
    auto LST = new LazySegmentTree(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) LST->set(i, A[i], B[i]);
    LST->build();
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            ll l, r, x; cin >> l >> r >> x;
            LST->update(l-1, r-1, pll{x%mod, 0});
        }
        else if(op == 2){
            ll l, r, x; cin >> l >> r >> x;
            LST->update(l-1, r-1, pll{0, x%mod});
        }
        else{
            ll l, r; cin >> l >> r;
            Node tmp = LST->query(l-1, r-1);
            cout << tmp.mul << '\n';
            // cout << tmp.A << ' ' << tmp.B << ' ' << tmp.mul << '\n';
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