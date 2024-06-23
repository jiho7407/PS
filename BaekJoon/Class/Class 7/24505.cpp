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

const ll mod = 1e9+7;

struct SegmentTree{
    vector<ll> tree;
    ll sz;

    ll pull(ll a, ll b){
        return (a+b)%mod;
    }

    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }

    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] += x;
        tree[idx] %= mod;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }

    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = 0;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret%mod;
    }
};

ll N;
vector<SegmentTree> st(11);

void solve(){
    cin >> N;
    rep(i, 0, 11) st[i].init(N+1);
    rep(i, 0, N){
        ll x; cin >> x;
        for(ll j = 10; j>0; j--){
            st[j].update(x, st[j-1].query(1, x-1));
        }
        st[0].update(x, 1);
    }
    cout << st[10].query(1, N) << '\n';
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