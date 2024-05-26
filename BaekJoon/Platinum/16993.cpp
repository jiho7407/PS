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

const ll llmin = -1e15;

struct Node{ll sum, pfsum, sfsum, mx;};

struct SegmentTree{
    ll sz;
    vector<Node> tree;
    SegmentTree(ll n, vector<ll> &arr){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz*2, {llmin, llmin, llmin, llmin});
        for(ll i = 0; i<n; i++){
            tree[sz+i] = {arr[i], arr[i], arr[i], arr[i]};
        }
        for(ll i = sz - 1; i>0; i--){
            tree[i] = pull(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    Node pull(Node a, Node b){
        Node ret = {llmin, llmin, llmin, llmin};
        ret.sum = a.sum + b.sum;
        ret.pfsum = max(a.pfsum, a.sum + b.pfsum);
        ret.sfsum = max(b.sfsum, b.sum + a.sfsum);
        ret.mx = max({a.mx, b.mx, a.sfsum + b.pfsum});
        return ret;
    }

    Node query(ll l, ll r){
        return query(1, 0, sz-1, l, r);
    }

    Node query(ll node, ll nl, ll nr, ll l, ll r){
        if(r < nl || nr < l) return {llmin, llmin, llmin, llmin};
        if(l <= nl && nr <= r) return tree[node];
        ll mid = (nl + nr) >> 1;
        Node left = query(node << 1, nl, mid, l, r);
        Node right = query(node << 1 | 1, mid + 1, nr, l, r);
        return pull(left, right);
    }
};

void solve(){
    ll N; cin >> N;
    vector<ll> arr(N);
    rep(i, 0, N) cin >> arr[i];
    SegmentTree st(N, arr);
    ll Q; cin >> Q;
    while(Q--){
        ll l, r; cin >> l >> r; l--; r--;
        cout << st.query(l, r).mx << '\n';
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