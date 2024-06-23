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

ll N, M;
ll A[1000][1000];
ll pfsum[1001][1001];
ll ul[1000][1000], ur[1000][1000], dl[1000][1000], dr[1000][1000];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];
    fill_n(&pfsum[0][0], 1001*1001, 0);
    rep(i, 0, N){
        rep(j, 0, N) pfsum[i+1][j+1] = pfsum[i][j+1] + pfsum[i+1][j] - pfsum[i][j] + A[i][j];
    }
    fill_n(&ul[0][0], 1000*1000, -1e1);
    fill_n(&ur[0][0], 1000*1000, -1e1);
    fill_n(&dl[0][0], 1000*1000, -1e1);
    fill_n(&dr[0][0], 1000*1000, -1e1);
    rep(i, M-1, N) rep(j, M-1, N){
        ul[i][j] = max({ul[i-1][j], ul[i][j-1], pfsum[i+1][j+1] - pfsum[i-M+1][j+1] - pfsum[i+1][j-M+1] + pfsum[i-M+1][j-M+1]});
    }
    rep(i, M-1, N) for(int j = N-M; j >= 0; j--){
        ur[i][j] = max({ur[i-1][j], ur[i][j+1], pfsum[i+1][j+M] - pfsum[i-M+1][j+M] - pfsum[i+1][j] + pfsum[i-M+1][j]});
    }
    for(int i = N-M; i >= 0; i--) rep(j, M-1, N){
        dl[i][j] = max({dl[i+1][j], dl[i][j-1], pfsum[i+M][j+1] - pfsum[i][j+1] - pfsum[i+M][j-M+1] + pfsum[i][j-M+1]});
    }
    for(int i = N-M; i >= 0; i--) for(int j = N-M; j >= 0; j--){
        dr[i][j] = max({dr[i+1][j], dr[i][j+1], pfsum[i+M][j+M] - pfsum[i][j+M] - pfsum[i+M][j] + pfsum[i][j]});
    }

    ll ans = 0;
    // ㅓ자형
    rep(i, 0, N-1) rep(j, 0, N-1) ans = max(ans, ul[i][j] + dl[i+1][j] + ur[N-1][j+1]);
    // ㅏ자형
    rep(i, 0, N-1) rep(j, 0, N-1) ans = max(ans, ul[N-1][j] + ur[i][j+1] + dr[i+1][j+1]);
    // ㅗ자형
    rep(i, 0, N-1) rep(j, 0, N-1) ans = max(ans, ul[i][j] + ur[i][j+1] + dl[i+1][N-1]);
    // ㅜ자형
    rep(i, 0, N-1) rep(j, 0, N-1) ans = max(ans, ul[i][N-1] + dl[i+1][j] + dr[i+1][j+1]);
    
    // ㅡ ㅡ ㅡ 자형
    auto ST1 = new SegmentTree();
    ST1->init(N+1);
    rep(i, M, N){
        ll mx = 0;
        rep(j, M, N) mx = max(mx, pfsum[i][j] - pfsum[i-M][j] - pfsum[i][j-M] + pfsum[i-M][j-M]);
        ST1->set(i-1, mx);
    }
    ST1->build();

    rep(i, M-1, N) rep(j, i+M, N-M){
        ans = max(ans, ul[i][N-1] + ST1->query(i+M, j) + dl[j+1][N-1]);
    }

    // ㅣ ㅣ ㅣ자형
    auto ST2 = new SegmentTree();
    ST2->init(N+1);
    rep(i, M, N){
        ll mx = 0;
        rep(j, M, N) mx = max(mx, pfsum[j][i] - pfsum[j-M][i] - pfsum[j][i-M] + pfsum[j-M][i-M]);
        ST2->set(i-1, mx);
    }
    ST2->build();

    rep(i, M-1, N) rep(j, i+M, N-M){
        ans = max(ans, ul[N-1][i] + ST2->query(i+M, j) + ur[N-1][j+1]);
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