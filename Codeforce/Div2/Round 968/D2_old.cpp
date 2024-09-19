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
    vector<ll> tree, lazy;
    ll sz;

    void init(ll n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(sz<<1, 0);
        lazy.assign(sz<<1, 0);
    }

    void pull(ll node){
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }

    void push(ll node, ll start, ll end){
        if(lazy[node] != 0){
            tree[node] = max(tree[node], lazy[node]);
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

    void update(ll node, ll start, ll end, ll left, ll right, ll val){
        push(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node] = max(lazy[node], val);
            push(node, start, end);
            return;
        }
        ll mid = (start + end)>>1;
        update(node<<1, start, mid, left, right, val);
        update(node<<1|1, mid+1, end, left, right, val);
        pull(node);
        return;
    }

    void pushall(){
        rep(i, 1, sz<<1) push(i, 0, 0);
    }

    ll sumall(int M){
        ll ret = 0;
        rep(i, 0, M) ret += tree[sz+i];
        return ret;
    }
};

pii mexex(set<int> &s){
    pii ret = {0, 0};
    int i = 0;
    while(s.count(i)) i++;
    ret.first = i;
    i++;
    while(s.count(i)) i++;
    ret.second = i;
    return ret;
}
vector<pair<int, pii>> mexs;

const int mxN = 2e5+1;
LazySegmentTree LST;

vector<pii> links[mxN];
int nxt[mxN];

int dfs(int cur, int idx){
    int &ret = nxt[cur];
    if(ret != -1) return ret;

    ret = cur;
    for(auto [id, n]: links[cur]){
        if(idx == id) continue;
        ret = max(ret, dfs(n, idx));
    }
    return ret;
}

void solve(){
    LST.init(mxN);

    ll N, M;
    cin >> N >> M;
    ll mx = -1;
    rep(i, 0, N){
        set<int> s;
        int cnt; cin >> cnt;
        while(cnt--){
            int x; cin >> x;
            s.insert(x);
        }
        pii ret = mexex(s);
        mexs.push_back({i, ret});
        mx = max(mx, (ll)ret.second);
        links[ret.first].push_back({i, ret.second});
    }
    fill(nxt, nxt+mxN, -1);
    rep(i, 0, mx+1) if(nxt[i] == -1) dfs(i, -1);
    rep(i, 0, mx+1) LST.update(i, i, nxt[i]);

    // rep(i, 0, mx+1) cout << nxt[i] << ' ';
    // cout << '\n';
    // LST.pushall();
    // rep(i, 0, mx+1) cout << LST.tree[LST.sz+i] << ' ';
    // cout << '\n';

    rep(i, 0, N){
        auto [idx, p] = mexs[i];
        auto [A, B] = p;
        fill(nxt, nxt+mx+1, -1);
        int ret = dfs(A, idx);
        // cout << A << ' ' << B << ' ' << ret << '\n';
        LST.update(0, A-1, ret);
        LST.update(A+1, ret-1, ret);
    }

    // LST.pushall();
    // rep(i, 0, mx+1) cout << LST.tree[LST.sz+i] << ' ';
    // cout << '\n';
    
    if(M <= mx){
        cout << LST.sumall(M+1) << '\n';
    }
    else{
        ll ret = 0;
        ret += LST.sumall(mx+1);
        ret += (ll)(M-mx)*(M+mx+1)/2;
        cout << ret << '\n';
    }

    rep(i, 0, mx+1) links[i].clear();
    mexs.clear();
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