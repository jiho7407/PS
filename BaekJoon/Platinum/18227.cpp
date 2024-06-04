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

struct SegmentTree{
    vector<ll> tree;
    ll sz;

    void pull(ll node){
        tree[node] = tree[node<<1]+tree[node<<1|1];
    }

    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, 0);
    }
    
    void set(ll i, ll x){
        tree[sz+i] = x;
    }

    void build(){
        for(ll i = sz-1; i > 0; i--) pull(i);
    }

    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) pull(idx);
    }
    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = 0;
        while(left <= right){
            if((left&1)==1) ret += tree[left++];
            if((right&1)==0) ret += tree[right--];
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

ll N, C, Q;
vector<ll> links[200001];
ll start[200001], finish[200001], depth[200001], idx = 0;

void dfs(ll cur, ll par, ll d){
    start[cur] = idx++;
    depth[cur] = d;
    for(auto nxt : links[cur]){
        if(nxt == par) continue;
        dfs(nxt, cur, d+1);
    }
    finish[cur] = idx - 1;
}

void solve(){
    cin >> N >> C;
    rep(i, 0, N-1){
        ll a, b; cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    dfs(C, -1, 1);
    auto ST = new SegmentTree();
    ST->init(N);
    ST->build();
    cin >> Q;
    while(Q--){
        ll op; cin >> op;
        if(op == 1){
            ll x; cin >> x;
            ST->update(start[x], 1);
        }else{
            ll x; cin >> x;
            cout << ST->query(start[x], finish[x])*depth[x] << '\n';
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