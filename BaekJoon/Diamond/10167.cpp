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

const ll MINF = -1e15;

struct Node{
    ll sum, pf, sf, mx;
};

struct SegmentTree{
    ll sz;
    vector<Node> tree;
    SegmentTree(ll n){
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

    void update(ll idx, ll val){
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

    Node query(ll l, ll r){
        if(l > r) return {0, MINF, MINF, MINF};
        return query(1, 0, sz-1, l, r);
    }

    Node query(ll node, ll cl, ll cr, ll ql, ll qr){
        if(qr < cl || cr < ql) return {0, MINF, MINF, MINF};
        if(ql <= cl && cr <= qr) return tree[node];
        ll mid = (cl + cr) / 2;
        Node left = query(node*2, cl, mid, ql, qr);
        Node right = query(node*2+1, mid+1, cr, ql, qr);
        return pull(left, right);
    }
};

ll N;
vector<tuple<ll, ll, ll>> mines;
vector<ll> Xs, Ys;
map<ll, ll> Xmp, Ymp;

void solve(){
    // 입력
    cin >> N;
    rep(i, 0, N){
        ll x, y, w; cin >> x >> y >> w;
        mines.push_back({x, y, w});
        Xs.push_back(x);
        Ys.push_back(y);
    }

    // 좌표 압축
    sort(Xs.begin(), Xs.end());
    Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
    sort(Ys.begin(), Ys.end());
    Ys.erase(unique(Ys.begin(), Ys.end()), Ys.end());
    rep(i, 0, Xs.size()) Xmp[Xs[i]] = i;
    rep(i, 0, Ys.size()) Ymp[Ys[i]] = i;
    rep(i, 0, N){
        auto [x, y, w] = mines[i];
        mines[i] = {Xmp[x], Ymp[y], w};
    }
    sort(mines.begin(), mines.end());

    // NlogN풀이 N번돌기
    SegmentTree ST(Ys.size());
    ll ans = 0;
    rep(i, 0, N){
        ST.clear();
        if(i > 0 && get<0>(mines[i]) == get<0>(mines[i-1])) continue;
        int j = i;
        while(j < N){
            int curx = get<0>(mines[j]);
            while(j < N && get<0>(mines[j]) == curx){
                ST.update(get<1>(mines[j]), get<2>(mines[j]));
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