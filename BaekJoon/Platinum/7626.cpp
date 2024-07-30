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

ll N;
vector<ll> Xs, Ys;
map<ll, ll> Xmp, Ymp;
vector<tuple<ll, bool, ll, ll>> query; // x, isEnd, y1, y2

// 0-1 Setment Tree
// 01 세그
// 화성지도 세그
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
        if(tree[idx] > 0) cnt[idx] = Ys[ne+1] - Ys[ns];
        else if (ns != ne) cnt[idx] = cnt[idx<<1] + cnt[idx<<1|1];
        else cnt[idx] = 0;
    }

    ll query(){
        return cnt[1];
    }
}ST;


void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        Xs.push_back(x1);
        Xs.push_back(x2);
        Ys.push_back(y1);
        Ys.push_back(y2);
        query.push_back({x1, 0, y1, y2});
        query.push_back({x2, 1, y1, y2});
    }
    sort(query.begin(), query.end());
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
    Ys.erase(unique(Ys.begin(), Ys.end()), Ys.end());
    rep(i, 0, Xs.size()) Xmp[Xs[i]] = i;
    rep(i, 0, Ys.size()) Ymp[Ys[i]] = i;
    
    ST.init(Ys.size());
    ll ans = 0;
    ll prevX = 0;
    for(auto [x, isEnd, y1, y2]: query){
        x = Xmp[x], y1 = Ymp[y1], y2 = Ymp[y2];
        // cout << Xs[prevX] << ' ' << Xs[x] << ' ' << ST.query() << '\n';
        ans += (Xs[x] - Xs[prevX]) * ST.query();
        prevX = x;
        if(isEnd) ST.update(y1, y2-1, -1);
        else ST.update(y1, y2-1, 1);
    }
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