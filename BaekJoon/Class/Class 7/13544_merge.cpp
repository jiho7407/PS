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

// Merge Sort Tree
struct MergeSortTree{
    int sz = 1;
    vector<vector<int>> tree;
    void init(int N, vector<int> &arr){
        while(sz < N) sz *= 2;
        tree.resize(2*sz);
        rep(i, 0, N) tree[sz+i].push_back(arr[i]);
        for(int i = sz-1; i>0; i--){
            int L = i<<1, R = i<<1|1;
            tree[i].resize(tree[L].size() + tree[R].size());
            merge(tree[L].begin(), tree[L].end(), tree[R].begin(), tree[R].end(), tree[i].begin());
        }
    }

    int query(int s, int e, int k){
        return query(1, 0, sz-1, s, e, k);
    }

    int query(int node, int ns, int ne, int s, int e, int k){
        if(ne < s || e < ns) return 0;
        if(s <= ns && ne <= e) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
        int mid = (ns+ne)>>1;
        return query(node<<1, ns, mid, s, e, k) + query(node<<1|1, mid+1, ne, s, e, k);
    }
}MST;

int N;
vector<int> A;

void solve(){
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];
    MST.init(N, A);
    int M; cin >> M;
    int ans = 0;
    while(M--){
        int a, b, c; cin >> a >> b >> c;
        a ^= ans, b ^= ans, c ^= ans;
        a--, b--;
        ans = MST.query(a, b, c);
        cout << ans << '\n';
    }
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