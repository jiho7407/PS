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

struct Line {
    mutable ll m, k, p;
    bool operator<(const Line& o) const { return m < o.m; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    //(for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { //floored division
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->m == y->m) x->p = x->k > y->k ? inf : -inf;
        else x->p = div(y->k - x->k, x->m - y->m);
        return x->p >= y->p;
    }
    void add(ll m, ll k) { //add y = mx + k
        auto z = insert({ m, k, 0 }), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    ll query(ll x) { // 최댓값 CHT. 최솟값일땐 m, k, query에 - 붙이기
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.k;
    }
};

vector<pii> seg[4*300010];
LineContainer CHT[4*300010];
map<pii, int> mp;
pii query[300010];
int ans[300010];

void update(int idx, int l, int r, int s, int e, pii val){
    if(e<l || r<s)return;
    if(s<=l && r<=e){
        seg[idx].push_back(val);
        return;
    }
    int m = (l+r)>>1;
    update(idx<<1, l, m, s, e, val);
    update(idx<<1|1, m+1, r, s, e, val);
}

void dfs(int idx, int l, int r){
    for(auto [a, b]: seg[idx]){
        CHT[idx].add(a, b);
    }
    if(l == r){
        if(ans[l] != -2e9){
            if(CHT[idx].empty()) cout << "EMPTY\n";
            else cout << CHT[idx].query(ans[l]) << '\n';
        }
        return;
    }
    int m = (l+r)>>1;
    CHT[idx<<1] = CHT[idx];
    CHT[idx<<1|1] = CHT[idx];
    dfs(idx<<1, l, m);
    dfs(idx<<1|1, m+1, r);
}


void solve(){
    int Q; cin >> Q;
    rep(i, 0, Q) ans[i] = -2e9;
    rep(i, 0, Q){
        int op; cin >> op;
        if(op == 1){
            int a, b; cin >> a >> b;
            query[i] = {a, b};
            mp[{a, b}] = i;
        }
        else if(op == 2){
            int j; cin >> j; j--;
            update(1, 0, Q-1, j, i, query[j]);
            mp.erase(query[j]);
        }
        else{
            cin >> ans[i];
        }
    }
    for(auto [k, v] : mp){
        update(1, 0, Q-1, v, Q-1, k);
    }
    dfs(1, 0, Q-1);
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