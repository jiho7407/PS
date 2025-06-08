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

// Lazy Segment Tree, Lazy Propagation
// 구간 업데이트, 구간 쿼리
struct LazySegmentTree{
    vector<pll> tree, lazy;
    // {flip, rotate}
    // R -> {0, 1}, L -> {0, 3}
    // H -> {1, 0}, V -> {1, 2}
    ll sz;

    LazySegmentTree(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, {0, 0});
        lazy.assign(sz<<1, {0, 0});
    }

    pll merge(pll a, pll b){
        pll ret = a;
        if(b.first == 1){
            ret.first = 1 - ret.first;
            ret.second = 4 - ret.second;
        }
        ret.second = (ret.second + b.second)%4;
        return ret;
    }

    void pull(ll node){
        tree[node] = merge(tree[node<<1], tree[node<<1|1]);
        assert(tree[node].first >= 0 && tree[node].first <= 1);
        assert(tree[node].second >= 0 && tree[node].second <= 3);
    }

    void push(ll node, ll start, ll end){
        if(lazy[node] == pll{0, 0}) return;
        tree[node] = pll{0, 0};
        rep(i, 0, (end-start+1)%4){
            tree[node] = merge(tree[node], lazy[node]);
        }
        if(start != end){
            lazy[node<<1] = lazy[node];
            lazy[node<<1|1] = lazy[node];
        }
        lazy[node] = pll{0, 0};
    }

    void set(ll idx, pll val){ tree[sz|idx] = val; }
    void build(){ for(ll i = sz-1; i > 0; i--) pull(i); }
    
    void update(ll left, ll right, pll diff){
        update(1, 0, sz-1, left, right, diff);
        return;
    }

    void update(ll node, ll start, ll end, ll left, ll right, pll diff){
        push(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node].first = diff.first;
            lazy[node].second = diff.second;
            push(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        pull(node);
        return;
    }

    pll query(ll left, ll right){
        return query(1, 0, sz-1, left, right);
    }

    pll query(ll node, ll start, ll end, ll left, ll right){
        push(node, start, end);
        if(left > end || right < start) return {0, 0};
        if(left <= start && end <= right) return tree[node];
        ll mid = (start + end)>>1;
        pll lq = query(node<<1, start, mid, left, right);
        pll rq = query(node<<1|1, mid+1, end, left, right);
        return merge(lq, rq);
    }
};

pll converter(char type){
    if(type == 'R') return {0, 1};
    if(type == 'L') return {0, 3};
    if(type == 'H') return {1, 0};
    if(type == 'V') return {1, 2};
    assert(false);
}

int N, M, Q;
string board[1000];
string S;
char rotater(pll ret, int r, int c){
    if(ret.second != 0){
        ret.second -= 1;
        return rotater(ret, N-1-c, r);
    }
    if(ret.first == 1) return board[r][N-1-c];
    return board[r][c];
}


void solve(){
    cin >> N;
    rep(i, 0, N) cin >> board[i];
    cin >> M >> S;
    LazySegmentTree LST(M);
    rep(i, 0, M){
        LST.set(i, converter(S[i]));
    }
    LST.build();
    
    cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int r, c; cin >> r >> c;
            r--, c--;
            cout << rotater(LST.query(0, M-1), r, c) << '\n';
        }
        else{
            int l, r; cin >> l >> r; l--, r--;
            char type; cin >> type;
            LST.update(l, r, converter(type));
        }
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