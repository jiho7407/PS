#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Node{
    ll mn, mx;
};

vector<Node> tree;

void push(ll node){
    ll lc = node<<1, rc = node<<1|1;
    tree[lc].mn = min(tree[lc].mn, tree[node].mn);
    tree[lc].mx = min(tree[lc].mx, tree[node].mn);
    tree[rc].mn = min(tree[rc].mn, tree[node].mn);
    tree[rc].mx = min(tree[rc].mx, tree[node].mn);

    tree[lc].mn = max(tree[lc].mn, tree[node].mx);
    tree[lc].mx = max(tree[lc].mx, tree[node].mx);
    tree[rc].mn = max(tree[rc].mn, tree[node].mx);
    tree[rc].mx = max(tree[rc].mx, tree[node].mx);
}

void update(ll op, ll node, ll start, ll end, ll left, ll right, ll height){
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        if(op == 1){
            tree[node].mn = max(tree[node].mn, height);
            tree[node].mx = max(tree[node].mx, height);
        }
        else{
            tree[node].mn = min(tree[node].mn, height);
            tree[node].mx = min(tree[node].mx, height);
        }
        return;
    }
    push(node);
    tree[node].mn = 1e9, tree[node].mx = 0;
    ll mid = (start + end)>>1;
    update(op, node<<1, start, mid, left, right, height);
    update(op, node<<1|1, mid+1, end, left, right, height);
}



int N, Q;

void solve(){
    cin >> N >> Q;
    ll sz = 1;
    while(sz < N) sz <<= 1;
    tree.resize(sz*2);
    while(Q--){
        ll op, left, right, height;
        cin >> op >> left >> right >> height;
        update(op, 1, 0, sz-1, left, right, height);
    }

    rep(i, 1, sz) push(i);
    rep(i, 0, N){
        cout << tree[sz+i].mn << "\n";
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