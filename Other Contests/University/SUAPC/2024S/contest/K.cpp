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

ll n, q, a, b, root;

ll sum(ll x) {
	ll ret = 0;
	ll r = 1;
	while (x <= n) {
		ll w = min(n, x + r - 1);
		ret += (x + w) * (w - x + 1) / 2;
		x *= 2;
		r *= 2;
	}
	return ret;
}

ll dep(ll x) {
	ll ret = 0;
	while (x >= (1LL << ret)) ret++;
	return ret;
}

ll lca(ll x, ll y) {
	ll dx = dep(x);
	ll dy = dep(y);
	if (dx > dy) {
		swap(x, y);
		swap(dx, dy);
	}
	ll z = dy - dx;
	while (z--) y /= 2;
	while (x != y) {
		x >>= 1;
		y >>= 1;
	}
	return x;
}

void solve(){
    cin >> n >> q;
	root = 1;
	while (q--) {
		cin >> a >> b;
		if (a == 1) root = b;
		else {
			ll w = lca(root, b);
			if (w == b) {
				ll ans = 0;
				ll e = root;
				while ((e >> 1) != b) e >>= 1;
				if (e == 2 * b) {
					while (b) {
						ans += b;
						ans += sum(2 * b + 1);
						b >>= 1;
					}
				}
				else {
					while (b) {
						ans += b;
						ans += sum(2 * b);
						b >>= 1;
					}
				}
				cout << ans;
			}
			else cout << sum(b);
			cout << "\n";
		}
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