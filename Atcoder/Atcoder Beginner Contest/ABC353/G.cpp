#include <bits/stdc++.h>
#define ll long long
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
    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, -1e18);
        for(ll i = sz-1; i > 0; i--){
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
        }
    }
    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = -1e18;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++]);
            if((right&1)==0) ret = max(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

ll N, C, M;

void solve(){
    cin >> N >> C >> M;
    SegmentTree STL, STR;
    STL.init(N+1);
    STR.init(N+1);
    STL.update(0, 0);
    STR.update(0, 0);
    ll ans = 0;
    rep(i, 0, M){
        ll T, P;
        cin >> T >> P; T--;
        ll left = STL.query(0, T) - T*C + P;
        ll right = STR.query(T, N) + T*C + P;
        ll mx = max(left, right);
        ans = max(ans, mx);
        STL.update(T, mx + T*C);
        STR.update(T, mx - T*C);
    }
    cout << ans << '\n';
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