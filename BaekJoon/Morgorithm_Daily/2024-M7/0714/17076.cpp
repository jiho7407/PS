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

struct MaxSegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return max(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}MaxST;

struct CntSegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return a+b;
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }

    int kth(int idx, int k){
        if(tree[idx] < k) return 1e9;
        if(idx >= sz) return idx - sz;

        if(tree[idx<<1] >= k) return kth(idx<<1, k);
        else return kth(idx<<1|1, k-tree[idx<<1]);
    }
}CntST;

int N;
int A[200000];
pii ans = {-1, -1};

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    MaxST.init(N);
    rep(i, 0, N) MaxST.set(i, A[i]);
    MaxST.build();
    CntST.init(200001);
    rep(i, 1, N) CntST.update(A[i], 1);

    rep(i, 1, N){
        CntST.update(A[i], -1);
        int cM = A[i];
        int cN = MaxST.query(0, i-1);
        int cK = CntST.kth(1, 2*cM);
        if(cN >= cK && ans < pii(cN, cM)) ans = {cN, cM};
    }
    if(ans.first == -1) cout << "-1\n";
    else cout << ans.first << ' ' << ans.second << '\n';
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