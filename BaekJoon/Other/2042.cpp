#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SegmentTree{
    ll tree[3000000], sz;
    void init(ll N){
        sz = 1;
        while(sz < N) sz *= 2;
        fill(tree, tree + 2*sz, 0);
    }
    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = tree[idx<<1] + tree[idx<<1|1];
        }
    }
    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = 0;
        while(left <= right){
            if(left % 2 == 1) ret += tree[left++];
            if(right % 2 == 0) ret += tree[right--];
            left /= 2;
            right /= 2;
        }
        return ret;
    }
};

ll N, M, K;
SegmentTree ST;

void solve(){
    cin >> N >> M >> K;
    ST.init(N);
    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;
        ST.update(i, x);
    }
    for(ll i = 0; i < M + K; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            ST.update(b-1, c);
        }else{
            cout << ST.query(b-1, c-1) << '\n';
        }
    }
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