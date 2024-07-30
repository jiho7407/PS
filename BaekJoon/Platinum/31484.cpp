#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int lines[50];
map<ll, ld> DP;

ld calc(ll st){
	int sz = __builtin_popcountll(st);
	if(sz <= 1) return 0;
	if(DP.count(st)) return DP[st];

	DP[st] = 1e9;
	rep(i, 0, N){
		ll nst1 = 0, nst2 = 0;
		rep(j, 0, M){
			if(st & (1LL << j)){
				if(lines[j] & (1 << i)) nst1 |= 1LL << j;
				else nst2 |= 1LL << j;
			}
		}
		ld ret = 1;
		ret += calc(nst1)*(__builtin_popcountll(nst1))/sz;
		ret += calc(nst2)*(__builtin_popcountll(nst2))/sz;
		DP[st] = min(DP[st], ret);
	}
	return DP[st];
}

void solve(){
	cin >> N >> M;
	ll status = 0;
	rep(i, 0, M){
		int cnt; cin >> cnt;
		rep(j, 0, cnt){
			int a; cin >> a;
			lines[i] |= 1 << a;
		}
		status |= (1LL << i);
	}

	sort(lines, lines+M);
	if(unique(lines, lines+M) != lines+M){
		cout << "not possible";
		return;
	}

	cout << fixed << setprecision(10) << calc(status);
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