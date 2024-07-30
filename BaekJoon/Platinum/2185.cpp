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

struct SegmentTree01{
    ll sz = 1;
    vector<ll> tree, cnt;

    void init(ll N){
        while(sz < N) sz <<= 1;
        tree.assign(sz<<1, 0);
        cnt.assign(sz<<1, 0);
    }

    void update(ll s, ll e, ll v){
        update(1, 0, sz-1, s, e, v);
    }

    void update(ll idx, ll ns, ll ne, ll s, ll e, ll v){
        if(e < ns || ne < s) return;
        if(s <= ns && ne <= e) tree[idx] += v;
        else{
            ll mid = (ns+ne)>>1;
            update(idx<<1, ns, mid, s, e, v);
            update(idx<<1|1, mid+1, ne, s, e, v);
        }
        if(tree[idx] > 0) cnt[idx] = ne-ns+1;
        else if (ns != ne) cnt[idx] = cnt[idx<<1] + cnt[idx<<1|1];
        else cnt[idx] = 0;
    }

    ll query(){
        return cnt[1];
    }
}ST;

ll N;
vector<tuple<ll, bool, ll, ll>> Xquery, Yquery; // x, isEnd, y1, y2

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        x1 += 1e5, y1 += 1e5, x2 += 1e5, y2 += 1e5;
        Xquery.push_back({x1, 0, y1, y2});
        Xquery.push_back({x2, 1, y1, y2});
        Yquery.push_back({y1, 0, x1, x2});
        Yquery.push_back({y2, 1, x1, x2});
    }
    sort(Xquery.begin(), Xquery.end());
    sort(Yquery.begin(), Yquery.end());

    ll ans = 0;

    ST.init(2e5+1);
    for(auto [x, isEnd, y1, y2]: Xquery){
        if(isEnd) ST.update(y1, y2-1, -1);
        else{
            ans -= ST.query();
            ST.update(y1, y2-1, 1);
            ans += ST.query();
        }
    }

    for(auto [y, isEnd, x1, x2]: Yquery){
        if(isEnd) ST.update(x1, x2-1, -1);
        else{
            ans -= ST.query();
            ST.update(x1, x2-1, 1);
            ans += ST.query();
        }
    }

    cout << ans*2 << '\n';
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