#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct LazySegmentTree{
    vector<ll> tree;
    vector<pair<ll, ll>> lazy;
    ll sz;
    pair<ll, ll> initpair = make_pair(1LL, 0LL);

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, 0);
        lazy.assign(sz<<1, initpair);
    }

    void set(ll idx, ll val){ tree[sz|idx] = val; }
    void build(){
        for(ll i = sz-1; i > 0; i--){
            tree[i] = (tree[i<<1] + tree[i<<1|1])%MOD;
        }
    }

    void propagate(ll node, ll start, ll end){
        if(lazy[node] == initpair) return;
        tree[node] = tree[node] * lazy[node].first + (end - start + 1) * lazy[node].second;
        tree[node] %= MOD;
        if(start != end){
            ll left = node<<1, right = node<<1|1;
            lazy[left].first *= lazy[node].first;
            lazy[left].second = lazy[left].second * lazy[node].first + lazy[node].second;
            lazy[left].first %= MOD;
            lazy[left].second %= MOD;

            lazy[right].first *= lazy[node].first;
            lazy[right].second = lazy[right].second * lazy[node].first + lazy[node].second;
            lazy[right].first %= MOD;
            lazy[right].second %= MOD;
        }
        lazy[node] = initpair;
        return;
    }

    void update(ll left, ll right, ll mul, ll pls){
        update(1, 0, sz-1, left, right, mul, pls);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, ll mul, ll pls){
        propagate(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node].first = mul;
            lazy[node].second = pls;
            propagate(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, mul, pls);
        update(node<<1|1, mid+1, end, left, right, mul, pls);
        tree[node] = tree[node<<1] + tree[node<<1|1];
        tree[node] %= MOD;
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
        return (query(node<<1, start, mid, left, right) + query(node<<1|1, mid+1, end, left, right))%MOD;
    }
};

int N;

void solve(){
    cin >> N;
    LazySegmentTree LST(N);
    rep(i, 0, N){
        ll x; cin >> x;
        LST.set(i, x);
    }
    LST.build();
    int M; cin >> M;
    while(M--){
        int q; cin >> q;
        if(q == 4){
            ll a, b; cin >> a >> b;
            cout << LST.query(a-1, b-1)%MOD << '\n';
        }
        else{
            ll a, b, v; cin >> a >> b >> v;
            if(q==1) LST.update(a-1, b-1, 1, v);
            else if(q==2) LST.update(a-1, b-1, v, 0);
            else if(q==3) LST.update(a-1, b-1, 0, v);
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