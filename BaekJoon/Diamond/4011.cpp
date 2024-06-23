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

struct SegmentTree{
    vector<ll> tree;
    ll sz;

    void pull(ll node){
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }

    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(ll i, ll x){
        tree[sz+i] = x;
    }

    void build(){
        for(ll i = sz-1; i > 0; i--) pull(i);
    }

    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) pull(idx);
    }
    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = 0;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++]);
            if((right&1)==0) ret = max(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

ll M, N, K;
ll A[1500][1500];
ll pfsum[1501][1501];
ll ul[1500][1500], ur[1500][1500], dl[1500][1500], dr[1500][1500];

void solve(){
    cin >> M >> N >> K;
    rep(i, 0, M) rep(j, 0, N) cin >> A[i][j];
    fill_n(&pfsum[0][0], 1501*1501, 0);
    rep(i, 0, M){
        rep(j, 0, N) pfsum[i+1][j+1] = pfsum[i][j+1] + pfsum[i+1][j] - pfsum[i][j] + A[i][j];
    }
    fill_n(&ul[0][0], 1500*1500, -1e2);
    fill_n(&ur[0][0], 1500*1500, -1e2);
    fill_n(&dl[0][0], 1500*1500, -1e2);
    fill_n(&dr[0][0], 1500*1500, -1e2);

    rep(i, K-1, M) rep(j, K-1, N){
        ul[i][j] = max({ul[i-1][j], ul[i][j-1], pfsum[i+1][j+1] - pfsum[i-K+1][j+1] - pfsum[i+1][j-K+1] + pfsum[i-K+1][j-K+1]});
    }
    rep(i, K-1, M) for(int j = N-K; j >= 0; j--){
        ur[i][j] = max({ur[i-1][j], ur[i][j+1], pfsum[i+1][j+K] - pfsum[i-K+1][j+K] - pfsum[i+1][j] + pfsum[i-K+1][j]});
    }
    for(int i = M-K; i >= 0; i--) rep(j, K-1, N){
        dl[i][j] = max({dl[i+1][j], dl[i][j-1], pfsum[i+K][j+1] - pfsum[i][j+1] - pfsum[i+K][j-K+1] + pfsum[i][j-K+1]});
    }
    for(int i = M-K; i >= 0; i--) for(int j = N-K; j >= 0; j--){
        dr[i][j] = max({dr[i+1][j], dr[i][j+1], pfsum[i+K][j+K] - pfsum[i][j+K] - pfsum[i+K][j] + pfsum[i][j]});
    }

    ll ans = 0;
    rep(i, 0, M-1) rep(j, 0, N-1){
        ans = max(ans, ul[i][j] + dl[i+1][j] + ur[M-1][j+1]); // ㅓ
        ans = max(ans, ul[i][j] + ur[i][j+1] + dl[i+1][N-1]); // ㅗ
        ans = max(ans, ul[N-1][j] + ur[i][j+1] + dr[i+1][j+1]); // ㅏ
        ans = max(ans, ul[i][N-1] + dl[i+1][j] + dr[i+1][j+1]); // ㅜ
    }
    
    // ㅡ ㅡ ㅡ 자형
    auto ST1 = new SegmentTree();
    ST1->init(M);
    rep(i, K, M+1){
        ll mx = 0;
        rep(j, K, N) mx = max(mx, pfsum[i][j] - pfsum[i-K][j] - pfsum[i][j-K] + pfsum[i-K][j-K]);
        ST1->set(i-1, mx);
    }
    ST1->build();

    rep(i, K-1, M-K) rep(j, i+K, M-K){
        ans = max(ans, ul[i][N-1] + ST1->query(i+K, j) + dl[j+1][N-1]);
    }

    // ㅣ ㅣ ㅣ자형
    auto ST2 = new SegmentTree();
    ST2->init(N);
    rep(i, K, N+1){
        ll mx = 0;
        rep(j, K, M) mx = max(mx, pfsum[j][i] - pfsum[j-K][i] - pfsum[j][i-K] + pfsum[j-K][i-K]);
        ST2->set(i-1, mx);
    }
    ST2->build();

    rep(i, K-1, N-K) rep(j, i+K, N-K){
        ans = max(ans, ul[N-1][i] + ST2->query(i+K, j) + ur[N-1][j+1]);
    }

    cout << ans;
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