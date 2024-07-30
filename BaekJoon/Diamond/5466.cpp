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

// Segment Tree
struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return max(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, -1e9);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = -1e9;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

int N, D, U, S;
vector<pii> market[500002];
SegmentTree DST, UST;

int calc(int L, int M){
    int ret = -1e9;
    ret = max(ret, DST.query(0, L) - L*D + M);
    ret = max(ret, UST.query(L, 500001) + L*U + M);
    return ret;
}

void solve(){
    cin >> N >> D >> U >> S;
    market[0].push_back({S, 0});
    rep(i, 0, N){
        int T, L, M; cin >> T >> L >> M;
        market[T].push_back({L, M});
    }
    DST.init(500002);
    UST.init(500002);
    DST.update(S, S*D);
    UST.update(S, -S*U);

    rep(i, 0, 500002){
        if(market[i].empty()) continue;
        sort(market[i].begin(), market[i].end());
        int sz = market[i].size();
        vector<int> DDP(sz), UDP(sz);
        rep(j, 0, sz){
            auto[L, M] = market[i][j];
            DDP[j] = UDP[j] = calc(L, M);
        }

        rep(j, 1, sz){
            auto [L, M] = market[i][j];
            DDP[j] = max(DDP[j], DDP[j-1] - (L - market[i][j-1].first)*D + M);
        }

        for(int j = sz-2; j >= 0; j--){
            auto [L, M] = market[i][j];
            UDP[j] = max(UDP[j], UDP[j+1] + (L - market[i][j+1].first)*U + M);
        }

        rep(j, 0, sz){
            auto [L, M] = market[i][j];
            DST.update(L, max(DDP[j], UDP[j]) + L*D);
            UST.update(L, max(DDP[j], UDP[j]) - L*U);
        }
        // for(auto D : DDP) cout << D << ' '; cout << '\n';
        // for(auto U : UDP) cout << U << ' '; cout << '\n';
    }

    cout << calc(S, 0) << '\n';
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