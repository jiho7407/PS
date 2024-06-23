#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int sq = 2000;
int N, C;
int A[300000];
int Q;
vector<tii> query;
int ans[10000];

bool cmp(tii a, tii b){
    auto [aL, aR, aidx] = a;
    auto [bL, bR, bidx] = b;
    if(aL/sq == bL/sq) return aR < bR;
    return aL/sq < bL/sq;
}

struct SegmentTree{
    vector<pii> tree;
    int sz;

    pii pull(pii a, pii b){
        if(a.first >= b.first) return a;
        else return b;
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
        rep(i, 0, sz) tree[sz+i] = {0, i};
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx].first += x;
        while(idx >>= 1) tree[idx] = pull(tree[2*idx], tree[2*idx+1]);
    }
    pii query(int L, int R){
        int left = L + sz, right = R + sz;
        pii ret = {0, 0};
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

void solve(){
    cin >> N >> C;
    rep(i, 0, N) cin >> A[i];
    cin >> Q;
    rep(i, 0, Q){
        int a, b; cin >> a >> b;
        a--; b--;
        query.push_back({a, b, i});
    }

    ST.init(C+100);
    sort(query.begin(), query.end(), cmp);
    int L = 0, R = -1;
    for(auto [a, b, idx]: query){
        while(a < L && L > 0){
            L--;
            ST.update(A[L], 1);
        }
        while(R < b && R < N-1){
            R++;
            ST.update(A[R], 1);
        }
        while(L < a && L < N){
            ST.update(A[L], -1);
            L++;
        }
        while(b < R && R >= 0){
            ST.update(A[R], -1);
            R--;
        }
        auto [cnt, val] = ST.query(1, C);
        if(cnt > (b-a+1)/2) ans[idx] = val;
        else ans[idx] = 0;
    }
    rep(i, 0, Q){
        if(ans[i]) cout << "yes " << ans[i] << '\n';
        else cout << "no\n";
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