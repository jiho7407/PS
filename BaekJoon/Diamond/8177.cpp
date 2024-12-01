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
        // if(tree[idx] > 0) cnt[idx] = Ys[ne+1] - Ys[ns]; // 좌표압축된 경우, 업데이트는 update(y1, y2-1)
        if(tree[idx] > 0) cnt[idx] = ne-ns+1;
        else if (ns != ne) cnt[idx] = cnt[idx<<1] + cnt[idx<<1|1];
        else cnt[idx] = 0;
    }

    ll query(){
        return cnt[1];
    }
}ST;

int N, M, K, D;

void solve(){ 
    cin >> N >> M >> K >> D;
    ST.init(N);
    ll cnt = 0;
    while(M--){
        int idx, val; cin >> idx >> val; idx--;
        ST.update(idx, idx+D, val);
        cnt += val;
        if(cnt <=)
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