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
    vector<unordered_map<int, int>> tree;
    vector<bool> lazy;
    ll sz;

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz<<1);
        lazy.resize(sz<<1);
    }

    void pull(ll node){
        unordered_map<int, int> &larger = tree[node<<1].size() > tree[node<<1|1].size() ? tree[node<<1] : tree[node<<1|1];
        unordered_map<int, int> &smaller = tree[node<<1].size() <= tree[node<<1|1].size() ? tree[node<<1] : tree[node<<1|1];
        tree[node] = larger;
        for (auto &p : smaller) {
            tree[node][p.first] += p.second;
        }
    }

    void set(ll idx, ll val){ tree[sz|idx][val] = 1; }
    void build(){
        for(ll i = sz-1; i > 0; i--){ pull(i); }
    }

    void propagate(ll node, ll start, ll end){
        if(lazy[node]){
            tree[node].clear();
            if(start != end){
                lazy[node<<1] = true;
                lazy[node<<1|1] = true;
            }
            lazy[node] = 0;
        }
    }

    void kill(ll left, ll right){
        update(1, 0, sz-1, left, right);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right){
        propagate(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node] = true;
            propagate(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right);
        update(node<<1|1, mid+1, end, left, right);
        pull(node);
        return;
    }

    ll query(ll left, ll right, ll k){
        return query(1, 0, sz-1, left, right, k);
    }

    ll query(ll node, ll start, ll end, ll left, ll right, ll k){
        propagate(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node][k];
        ll mid = (start + end)>>1;
        return query(node<<1, start, mid, left, right, k) + query(node<<1|1, mid+1, end, left, right, k);
    }
};

void solve(){
    int N; cin >> N;
    LazySegmentTree LST(N);
    rep(i, 0, N){
        int A; cin >> A;
        LST.set(i, A);
    }
    LST.build();
    int Q; cin >> Q;
    while(Q--){
        int cmd, l, r, k;
        cin >> cmd >> l >> r;
        l--; r--;
        if(cmd == 1){
            cin >> k;
            cout <<  LST.query(l, r, k) << "\n";
        }
        else{
            LST.kill(l, r);
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