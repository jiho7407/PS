#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct LazySegmentTree{
public:
    vector<ll> tree, lazy;
    ll lg, sz;
    LazySegmentTree(ll n){
        lg = 0;
        while(n > (1 << lg)) lg++;
        sz = 1 << lg;
        tree.resize(sz*2, 0);
        lazy.resize(sz*2, 0);
    }

    void set(ll idx, ll val){ tree[sz|idx] = val; }
    void build(){
        for(ll i = sz-1; i > 0; i--){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    void apply(ll i, ll len, ll val){
        tree[i] += len * val;
        if(i < sz) lazy[i] += val;
    }

    void push(ll i) {
        ll len = (sz >> (__builtin_ctzll(i) - 1)); // Node i의 원소 개수
        apply(i << 1, len / 2, lazy[i]);
        apply(i << 1 | 1, len / 2, lazy[i]);
        lazy[i] = 0;
    }

    void pull(ll i){
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(ll l, ll r, ll value) {
        l += sz, r += sz;
        ll l0 = l, r0 = r;
        for (ll i = lg; i > 0; --i) { // down
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != (r >> i)) push(r >> i);
        }
        ll len = 1;
        while (l <= r) {
            if (l & 1) apply(l++, len, value);
            if (!(r & 1)) apply(r--, len, value);
            l >>= 1, r >>= 1, len <<= 1;
        }
        for (ll i = 1; i <= lg; ++i) { // up
            if (((l0 >> i) << i) != l0) pull(l0 >> i);
            if (((r0 >> i) << i) != (r0 >> i)) pull(r0 >> i);
        }
    }

    ll query(ll l, ll r) {
        l += sz, r += sz;
        for (ll i = lg; i > 0; --i) { // down
            if (((l >> i) << i) != l) push(l >> i);›
            if (((r >> i) << i) != (r >> i)) push(r >> i);
        }
        ll res = 0;
        for(; l <= r; l >>= 1, r >>= 1){
            if(l & 1) res += tree[l++];
            if(!(r & 1)) res += tree[r--];
        }
        return res;
    }
};

ll N, M, K;

void solve(){
    cin >> N >> M >> K;
    LazySegmentTree LST(N);
    rep(i, 1, N+1){
        ll x; cin >> x;
        LST.set(i, x);
    }
    LST.build();
    rep(i, 1, LST.sz*2) cout << LST.tree[i] << ' ';
    cout << '\n';
    rep(i, 1, LST.sz*2) cout << LST.lazy[i] << ' ';
    cout << '\n';
    rep(i, 0, M+K){
        ll cmd, a, b, c; cin >> cmd;
        if(cmd == 1){
            cin >> a >> b >> c;
            LST.update(a, b, c);
        }
        else{
            cin >> a >> b;
            cout << LST.query(a, b) << '\n';
        }
        rep(i, 1, LST.sz*2) cout << LST.tree[i] << ' ';
        cout << '\n';
        rep(i, 1, LST.sz*2) cout << LST.lazy[i] << ' ';
        cout << '\n';
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