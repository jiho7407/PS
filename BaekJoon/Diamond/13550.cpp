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

int sq, sz;
struct Query{
    int idx, l, r;

    Query(int idx, int l, int r): idx(idx), l(l), r(r){}

    bool operator<(const Query &q) const{
        if(l/sq == q.l/sq) return r < q.r;
        return l/sq < q.l/sq;
    }
};

int N, M, K;
int A[101000], ans[101000];
vector<Query> Q;

list<int> dq[1000000];
int cnt[101000], bucket[350];

void Plus(int idx, bool isfront){
    int now = 0;
    auto &cur = dq[A[idx]];
    if(!cur.empty()){
        now = cur.back() - cur.front();
        cnt[now]--; bucket[now/sq]--;
    }
    if(isfront) cur.push_front(idx);
    else cur.push_back(idx);
    now = cur.back() - cur.front();
    cnt[now]++; bucket[now/sq]++;
}

void Minus(int idx, bool isfront){
    int now = 0;
    auto &cur = dq[A[idx]];
    now = cur.back() - cur.front();
    cnt[now]--; bucket[now/sq]--;
    if(isfront) cur.pop_front();
    else cur.pop_back();
    if(!cur.empty()){
        now = cur.back() - cur.front();
        cnt[now]++; bucket[now/sq]++;
    }
}

int query(){
    for(int i = sz-1; i >= 0; i--){
        if(bucket[i] == 0) continue;
        for(int j = sq-1; j >= 0; j--){
            if(cnt[i*sq+j] > 0) return i*sq+j;
        }
    }
    return 0;
}

void solve(){
    cin >> N >> K; N++;
    sq = sqrt(N); sz = (N-1)/sq+1;
    rep(i, 1, N) cin >> A[i];
    rep(i, 1, N) A[i] = (A[i-1] + A[i] + K)%K;
    cin >> M;
    rep(i, 0, M){
        int l, r; cin >> l >> r; l--; r;
        Q.push_back(Query(i, l, r));
    }
    sort(Q.begin(), Q.end());

    fill(bucket, bucket+350, 0);
    fill(cnt, cnt+101000, 0);

    int lp = 0, rp = -1;
    for(auto [idx, l, r]: Q){
        while(l < lp) Plus(--lp, 1);
        while(rp < r) Plus(++rp, 0);
        while(lp < l) Minus(lp++, 1);
        while(r < rp) Minus(rp--, 0);
        ans[idx] = query();
    }
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