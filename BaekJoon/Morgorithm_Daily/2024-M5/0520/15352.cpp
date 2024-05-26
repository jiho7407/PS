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

const ll mxN = 1e6+10;
ll K, N, Q;
ll A[mxN], root[mxN], cnt[mxN];

ll findroot(ll x){
    if(root[x] == x) return x;
    return root[x] = findroot(root[x]);
}

void merge(ll x, ll y){
    x = findroot(x);
    y = findroot(y);
    if(x == y) return;
    if(x>y) swap(x, y);
    root[y] = x;
    cnt[x] += cnt[y];
    return;
}

struct SegmentTree{
    vector<ll> tree;
    ll sz;

    void pull(ll node){
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, 1);
        for(ll i = sz-1; i > 0; i--){
            pull(i);
        }
    }
    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            pull(idx);
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

    ll find(ll x){
        ll node = 1;
        while(node < sz){
            if(tree[node<<1] < x){
                x -= tree[node<<1];
                node = node<<1|1;
            }
            else node = node<<1;
        }
        return node - sz;
    }
}ST;



void solve(){
    cin >> K >> N;
    A[0] = A[N+1] = -1;
    rep(i, 1, N+1) cin >> A[i];
    rep(i, 0, N+2) root[i] = i;
    fill(cnt, cnt+N+2, 1);
    rep(i, 0, N+1) if(A[i] == A[i+1]) merge(i, i+1);
    ST.init(N+2);
    cin >> Q;
    ll ans = 0;
    while(Q--){
        ll a, b; cin >> a >> b;
        if(a == 2) ans += cnt[findroot(b)];
        else{
            ST.update(b, 0);
            ll sum = ST.query(0, b);
            ll left = ST.find(sum);
            ll right = ST.find(sum+1);
            cnt[findroot(b)]--;
            if(left != 0 && right != N+1 && A[left] == A[right]){
                merge(left, right);
            }
        }
    }
    cout << ans << '\n';
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