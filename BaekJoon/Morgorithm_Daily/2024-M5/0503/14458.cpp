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

struct SegmentTree{
    vector<ll> tree;
    ll sz;
    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, 0);
    }
    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = (tree[idx<<1]+tree[idx<<1|1]);
        }
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

const ll mxN = 1e5;
ll N;
ll A[mxN], B[mxN];
map<ll, ll> mp;
vector<ll> order;

ll calc(ll A[], ll B[]){
    mp.clear();
    order.clear();
    rep(i, 0, N) mp[B[i]-1] = i;
    rep(i, 0, N) order.push_back(mp[A[i]-1]);
    SegmentTree ST;
    ST.init(N);
    ll tmp = 0;
    rep(i, 0, N){
        tmp += ST.query(order[i], N-1);
        ST.update(order[i], 1);
    }
    ll ans = tmp;
    for(ll i = N-1; i >= 0; i--){
        tmp += (order[i]) - (N-order[i]-1);
        ans = min(ans, tmp);
    }
    return ans;
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    cout << min(calc(A, B), calc(B, A));
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