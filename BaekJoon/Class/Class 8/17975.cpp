#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int MINF = -1e9;

struct Node{
    int sum, pf, sf, mx;
};

struct SegmentTree{
    int sz;
    vector<Node> tree;
    SegmentTree(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz*2, {0, MINF, MINF, MINF});
    }

    void clear(){
        rep(i, 0, sz*2) tree[i] = {0, MINF, MINF, MINF};
    }

    Node pull(Node &a, Node &b){
        Node ret;
        ret.sum = a.sum + b.sum;
        ret.pf = max(a.pf, a.sum + b.pf);
        ret.sf = max(b.sf, b.sum + a.sf);
        ret.mx = max({a.mx, b.mx, a.sf + b.pf});
        return ret;
    }

    void update(int idx, int val){
        idx += sz;
        if(tree[idx].mx == MINF) tree[idx] = {val, val, val, val};
        else{
            tree[idx].sum += val;
            tree[idx].pf += val;
            tree[idx].sf += val;
            tree[idx].mx += val;
        }
        while(idx >>= 1){
            tree[idx] = pull(tree[idx<<1], tree[idx<<1 | 1]);
        }
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

int N1, N2, c1, c2;
vector<tuple<int, int, int>> balls;
vector<int> Xs, Ys;
map<int, int> Xmp, Ymp;

void solve(){
    // 입력
    cin >> N1;
    rep(i, 0, N1){
        int x, y; cin >> x >> y;
        Xs.push_back(x);
        Ys.push_back(y);
        balls.push_back({x, y, 1}); // 1: 스트라이크
    }
    cin >> N2;
    rep(i, 0, N2){
        int x, y; cin >> x >> y;
        Xs.push_back(x);
        Ys.push_back(y);
        balls.push_back({x, y, 2}); // 2: 볼
    }
    cin >> c1 >> c2;

    // 좌표 압축
    sort(Xs.begin(), Xs.end());
    Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
    sort(Ys.begin(), Ys.end());
    Ys.erase(unique(Ys.begin(), Ys.end()), Ys.end());
    rep(i, 0, Xs.size()) Xmp[Xs[i]] = i;
    rep(i, 0, Ys.size()) Ymp[Ys[i]] = i;
    rep(i, 0, balls.size()){
        auto [x, y, c] = balls[i];
        balls[i] = {Xmp[x], Ymp[y], c};
    }
    sort(balls.begin(), balls.end());

    // NlogN풀이 N번돌기
    SegmentTree ST(Ys.size());
    int ans = 0;
    rep(i, 0, balls.size()){
        ST.clear();
        if(i > 0 && get<0>(balls[i]) == get<0>(balls[i-1])) continue;
        int j = i;
        while(j < balls.size()){
            int curx = get<0>(balls[j]);
            while(j < balls.size() && get<0>(balls[j]) == curx){
                ST.update(get<1>(balls[j]), (get<2>(balls[j]) == 1 ? c1 : -c2));
                j++;
            }
            ans = max(ans, ST.query(0, Ys.size()-1).mx);
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