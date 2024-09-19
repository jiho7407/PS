#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct LazySegmentTree{
    vector<int> tree, lazy;
    int sz;

    LazySegmentTree(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, 0);
        lazy.assign(sz<<1, 0);
    }

    void pull(ll node){
        tree[node] = tree[node<<1] + tree[node<<1|1];
        tree[node] %= 256;
    }

    void push(ll node, ll start, ll end){
        if(lazy[node] != 0){
            tree[node] += (end - start + 1) * lazy[node];
            tree[node] %= 256;
            if(start != end){
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void set(ll idx, ll val){ tree[sz|idx] = val; }
    void build(){ for(ll i = sz-1; i > 0; i--) pull(i); }
    
    void update(ll left, ll right, ll diff){
        update(1, 0, sz-1, left, right, diff);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, ll diff){
        push(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node] += diff;
            push(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        pull(node);
        return;
    }

    ll query(ll left, ll right){
        return query(1, 0, sz-1, left, right);
    }

    ll query(ll node, ll start, ll end, ll left, ll right){
        push(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        ll mid = (start + end)>>1;
        ll lq = query(node<<1, start, mid, left, right);
        ll rq = query(node<<1|1, mid+1, end, left, right);
        return lq + rq;
    }
};

int N, M, Q;
vector<LazySegmentTree> data;

void solve(){
    cin >> N >> M >> Q;
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