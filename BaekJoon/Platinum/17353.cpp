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
    vector<ll> tree, lazy;
    ll sz;

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, 0);
        lazy.assign(sz<<1, 0);
    }

    void set(ll idx, ll val){ tree[sz|idx] = val; }
    void build(){
        for(ll i = sz-1; i > 0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];
    }

    void propagate(ll node, ll start, ll end){
        if(lazy[node] != 0){
            tree[node] += (end - start + 1) * lazy[node];
            if(start != end){
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(ll left, ll right, ll diff){
        update(1, 0, sz-1, left, right, diff);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, ll diff){
        propagate(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            tree[node] += (end - start + 1) * diff;
            if(start != end){
                lazy[node<<1] += diff;
                lazy[node<<1|1] += diff;
            }
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        tree[node] = tree[node<<1] + tree[node<<1|1];
        return;
    }

    ll query(ll left, ll right){
        return query(1, 0, sz-1, left, right);
    }

    ll query(ll node, ll start, ll end, ll left, ll right){
        propagate(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        ll mid = (start + end)>>1;
        return query(node<<1, start, mid, left, right) + query(node<<1|1, mid+1, end, left, right);
    }
};

int N, Q;
int A[100001];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    LazySegmentTree LST(N+1);
    LST.set(0, A[0]);
    rep(i, 1, N){
        LST.set(i, A[i] - A[i-1]);
    }
    LST.build();
    cin >> Q;
    while(Q--){
        int q, a, b;
        cin >> q;
        if(q == 1){
            cin >> a >> b;
            LST.update(a-1, b-1, 1);
            LST.update(b, b, (b-a+1)*(-1));
        }else{
            cin >> a;
            cout << LST.query(0, a-1) << '\n';
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