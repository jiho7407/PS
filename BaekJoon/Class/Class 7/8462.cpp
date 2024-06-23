#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll sq = 500;
ll N, Q;
ll A[100000];
ll cnt[1000001];
ll ans[100000];

vector<tii> query;
ll ret = 0;

bool cmp(tii a, tii b){
    auto [al, ar, aidx] = a;
    auto [bl, br, bidx] = b;
    if(al/sq != bl/sq) return al/sq < bl/sq;
    return ar < br;
}

void add(ll x){
    ret -= cnt[x]*cnt[x]*x;
    cnt[x]++;
    ret += cnt[x]*cnt[x]*x;
}

void sub(ll x){
    ret -= cnt[x]*cnt[x]*x;
    cnt[x]--;
    ret += cnt[x]*cnt[x]*x;
}

void solve(){
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, Q){
        ll a, b; cin >> a >> b;
        a--; b--;
        query.push_back({a, b, i});
    }
    sort(query.begin(), query.end(), cmp);
    ll l = 0, r = -1;
    for(auto [s, e, idx]: query){
        while(s < l) add(A[--l]);
        while(r < e) add(A[++r]);
        while(l < s) sub(A[l++]);
        while(e < r) sub(A[r--]);
        ans[idx] = ret;
    }
    rep(i, 0, Q) cout << ans[i] << '\n';
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