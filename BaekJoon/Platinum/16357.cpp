#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


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
        for(ll i = sz-1; i > 0; i--) tree[i] = max(tree[i<<1], tree[i<<1|1]);
    }

    void propagate(ll node, ll start, ll end){
        if(lazy[node] != 0){
            tree[node] += lazy[node];
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
            lazy[node] += diff;
            propagate(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, diff);
        update(node<<1|1, mid+1, end, left, right, diff);
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
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
        return max(query(node<<1, start, mid, left, right), query(node<<1|1, mid+1, end, left, right));
    }
};

ll N;
vector<ll> ylst;
map<ll, ll> comp;
vector<pii> lines;
vector<tuple<ll, bool, ll>> endpoints; // (좌표, 끝점 여부, 선분 인덱스)

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
        lines.push_back({y1, y0});
        endpoints.push_back({y1, 0, i});
        endpoints.push_back({y0, 1, i});
        ylst.push_back(y0);
        ylst.push_back(y1);
    }
    sort(ylst.begin(), ylst.end());
    ylst.erase(unique(ylst.begin(), ylst.end()), ylst.end());
    rep(i, 0, ylst.size()) comp[ylst[i]] = i;
    rep(i, 0, 2*N) get<0>(endpoints[i]) = comp[get<0>(endpoints[i])];
    sort(endpoints.begin(), endpoints.end());

    LazySegmentTree LST(ylst.size());
    for(auto [a, b]: lines) LST.update(comp[a], comp[b], 1);
    ll ans = 0, curline = 0;
    for(auto [x, end, idx]: endpoints){
        if(end){
            LST.update(comp[lines[idx].first], comp[lines[idx].second], 1);
            curline--;
        }
        else{
            LST.update(comp[lines[idx].first], comp[lines[idx].second], -1);
            curline++;
        }
        ans = max(ans, curline + LST.query(0, LST.sz-1));
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}