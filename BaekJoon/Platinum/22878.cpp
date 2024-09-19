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

int N;
vector<pll> v;
vector<ll> tmp;

ll calc(){
    ll ret = 0;
    sort(tmp.begin(), tmp.end());
    rep(i, 0, N) ret += i * tmp[i];
    rep(i, 0, N) ret -= (N-i-1) * tmp[i];
    tmp.clear();
    return ret;
}


void solve(){
    cin >> N;
    v.resize(N);
    rep(i, 0, N) cin >> v[i].first;
    rep(i, 0, N) cin >> v[i].second;

    ll ans = 0;

    rep(i, 0, N) tmp.push_back(v[i].first);
    ans += calc()*2;

    rep(i, 0, N) tmp.push_back(v[i].second);
    ans += calc()*2;

    rep(i, 0, N) tmp.push_back(v[i].first + v[i].second);
    ans -= calc();

    rep(i, 0, N) tmp.push_back(v[i].first - v[i].second);
    ans -= calc();

    cout << ans << '\n';
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