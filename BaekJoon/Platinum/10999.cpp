#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll mxN = 1 << 20;
ll N, M, K;
ll tree[mxN*4], lazy[mxN*4];

void update(ll node, ll start, ll end, ll left, ll right, ll diff){
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        tree[node] += (end - start + 1) * diff;
        if(start != end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    ll mid = (start + end) / 2;
    update(node*2, start, mid, left, right, diff);
    update(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}

ll query(ll node, ll start, ll end, ll left, ll right){
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll mid = (start + end) / 2;
    return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
}

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N) cin >> tree[mxN+i];
    for(ll i = mxN-1; i > 0; i--) tree[i] = tree[i*2] + tree[i*2+1];
    rep(i, 0, M+K){
        ll cmd, a, b, c; cin >> cmd;
        if(cmd == 1){
            cin >> a >> b >> c;
            update(1, 0, mxN-1, a-1, b-1, c);
        }
        else{
            cin >> a >> b;
            cout << query(1, 0, mxN-1, a-1, b-1) << '\n';
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