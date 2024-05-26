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

const ll MINF = -1e15;

struct Node{
    ll sum, pf, sf, mx;
};

struct SegmentTree{
    int sz;
    vector<Node> tree;
    SegmentTree(int n, vector<ll> &arr){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz*2, {0, MINF, MINF, MINF});
        rep(i, 0, n) tree[sz+i] = {arr[i], arr[i], arr[i], arr[i]};
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1 | 1]);
    }

    Node pull(Node &a, Node &b){
        Node ret;
        ret.sum = a.sum + b.sum;
        ret.pf = max(a.pf, a.sum + b.pf);
        ret.sf = max(b.sf, b.sum + a.sf);
        ret.mx = max({a.mx, b.mx, a.sf + b.pf});
        return ret;
    }

    Node query(int l, int r){
        if(l > r) return {0, MINF, MINF, MINF};
        return query(1, 0, sz-1, l, r);
    }

    Node query(int node, int cl, int cr, int ql, int qr){
        if(qr < cl || cr < ql) return {0, MINF, MINF, MINF};
        if(ql <= cl && cr <= qr) return tree[node];
        int mid = (cl + cr) / 2;
        Node left = query(node*2, cl, mid, ql, qr);
        Node right = query(node*2+1, mid+1, cr, ql, qr);
        return pull(left, right);
    }
};


int N, M;
vector<ll> A;

void solve(){
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];
    SegmentTree ST(N, A);
    // rep(i, 0, ST.sz*2) cout << ST.tree[i].sf << " ";
    // cout << '\n';
    cin >> M;
    while(M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if(y1 < x2){
            Node a = ST.query(x1, y1);
            Node b = ST.query(y1+1, x2-1);
            Node c = ST.query(x2, y2);
            cout << a.sf + b.sum + c.pf << '\n';
        }
        else{
            Node a = ST.query(x1, x2-1);
            Node b = ST.query(x2, y1);
            Node c = ST.query(y1+1, y2);
            ll ret = MINF;
            ret = max(ret, a.sf + b.sum + c.pf);
            ret = max(ret, a.sf + b.pf);
            ret = max(ret, b.sf + c.pf);
            ret = max(ret, b.mx);
            cout << ret << '\n';
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