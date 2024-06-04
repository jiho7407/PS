# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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

int sq;
struct Query{
    int l, r, idx;
    Query(int l, int r, int idx): l(l), r(r), idx(idx){}
    bool operator<(const Query &q) const{
        if(l/sq == q.l/sq) return r < q.r;
        return l/sq < q.l/sq;
    }
};


const int mxN = 1e6;
int N, Q, ret = 0;
int A[mxN], ans[mxN], cnt[mxN];
vector<Query> query;

void compress(int *A){
    vector<int> B(A, A+N);
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    rep(i, 0, N) A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    return;
}

void Plus(int idx){
    if(++cnt[A[idx]] == 1) ret++;
    return;
}

void Minus(int idx){
    if(--cnt[A[idx]] == 0) ret--;
    return;
}

void solve(){
    cin >> N; sq = sqrt(N);
    rep(i, 0, N) cin >> A[i];
    compress(A);

    cin >> Q;
    rep(i, 0, Q){
        int l, r; cin >> l >> r; l--, r--;
        query.push_back(Query(l, r, i));
    }
    sort(query.begin(), query.end());

    int lp = 0, rp = -1;
    for(auto [l, r, idx]: query){
        while(l < lp) Plus(--lp);
        while(rp < r) Plus(++rp);
        while(lp < l) Minus(lp++);
        while(r < rp) Minus(rp--);
        ans[idx] = ret;
    }
    rep(i, 0, Q) cout << ans[i] << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}