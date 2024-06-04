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
    int idx, l, r;

    // 생성자
    Query(int idx, int l, int r): idx(idx), l(l), r(r){}

    // < 연산자 오버로딩
    bool operator<(const Query &q) const{
        if(l/sq == q.l/sq) return r < q.r;
        return l/sq < q.l/sq;
    }
};

int N, M;
int A[100000], ans[100000];
vector<Query> Q;

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];

    sq = sqrt(N);
    rep(i, 0, M){
        int l, r; cin >> l >> r; l--; r--;
        Q.push_back(Query(i, l, r));
    }
    sort(Q.begin(), Q.end());

    ll sum = 0;
    int lp = Q[0].l, rp = Q[0].r;
    rep(i, lp, rp+1) sum += A[i];
    ans[Q[0].idx] = sum;
    rep(i, 1, M){
        auto [idx, l, r] = Q[i];
        while(lp < l) sum -= A[lp++];
        while(lp > l) sum += A[--lp];
        while(rp < r) sum += A[++rp];
        while(rp > r) sum -= A[rp--];
        ans[idx] = sum;    }

    rep(i, 0, M) cout << ans[i] << '\n';

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