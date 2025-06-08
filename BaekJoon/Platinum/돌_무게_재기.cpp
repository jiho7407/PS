#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int sz = 1;
pii tree[400040];
int lazy[400040];

pii pull(pii a, pii b){
    return {min(a.first, b.first), max(a.second, b.second)};
}

void push(int node, int s, int e){
    if(lazy[node] != 0){
        tree[node].first += lazy[node];
        tree[node].second += lazy[node];
        if(s != e){
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int qs, int qe, int diff){
    push(node, s, e);
    if(e < qs || qe < s) return;
    if(qs <= s && e <= qe){
        lazy[node] += diff;
        push(node, s, e);
        return;
    }
    int mid = (s + e) >> 1;
    update(node<<1, s, mid, qs, qe, diff);
    update(node<<1|1, mid+1, e, qs, qe, diff);
    tree[node] = pull(tree[node<<1], tree[node<<1|1]);
}

void solve(){
    cin >> N;
    while(sz < N) sz <<= 1;
    rep(i, 0, N){
        int m, d; cin >> m >> d;
        update(1, 0, sz-1, 0, m-1, (d == 1) ? -1 : 1);
        if(tree[1].first >= 0) cout << "<\n";
        else if(tree[1].second <= 0) cout << ">\n";
        else cout << "?\n";
    }
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