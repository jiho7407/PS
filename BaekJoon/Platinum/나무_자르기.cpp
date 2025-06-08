#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Line {
    mutable ll m, k, p;
    bool operator<(const Line& o) const { return m < o.m; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    //(for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { //floored division
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->m == y->m) x->p = x->k > y->k ? inf : -inf;
        else x->p = div(y->k - x->k, x->m - y->m);
        return x->p >= y->p;
    }
    void add(ll m, ll k) { //add y = mx + k
        auto z = insert({ m, k, 0 }), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    ll query(ll x) { // 최댓값 CHT. 최솟값일땐 m, k, query에 - 붙이기
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.k;
    }
}CHT;

void solve(){
    ll N; cin >> N;
    vector<ll> A(N), B(N), DP(N);
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) cin >> B[i];

    DP[0] = 0;
    CHT.add(-B[0], -DP[0]);
    rep(i,1,N){
        DP[i] = -CHT.query(A[i]);
        CHT.add(-B[i], -DP[i]);
    }
    cout << DP[N-1] << '\n';
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