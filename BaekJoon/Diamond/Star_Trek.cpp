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
        m *= -1; k *= -1;
		auto z = insert({ m, k, 0 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return -(l.m * x + l.k);
	}
}CHT;

void solve(){
    int N; cin >> N;
    vector<ll> dist(N);
    rep(i, 1, N) cin >> dist[i], dist[i] += dist[i-1];
    vector<ll> DP(N);
    rep(i, 0, N) DP[i] = 1e18;
    DP[0] = 0;
    rep(i, 0, N-1){
        if(i) DP[i] = CHT.query(dist[i]);
        ll p, s; cin >> p >> s;
        CHT.add(s, DP[i]+p-s*dist[i]);
    }
    cout << CHT.query(dist[N-1]) << "\n";
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