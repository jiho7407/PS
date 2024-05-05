#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SegmentTreeMx{
    vector<int> tree;
    int sz;
    void init(int N, vector<int>& lst){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
        for(int i = 0; i < N; i++){
            tree[sz+i] = lst[i];
        }
        for(int i = sz-1; i > 0; i--){
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
        }
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++]);
            if((right&1)==0) ret = max(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

struct SegmentTreeMn{
    vector<int> tree;
    int sz;
    void init(int N, vector<int>& lst){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, 1e9);
        for(int i = 0; i < N; i++){
            tree[sz+i] = lst[i];
        }
        for(int i = sz-1; i > 0; i--){
            tree[i] = min(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = min(tree[idx<<1], tree[idx<<1|1]);
        }
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 1e9;
        while(left <= right){
            if((left&1)==1) ret = min(ret, tree[left++]);
            if((right&1)==0) ret = min(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

void solve(){
    int N, M, C; cin >> N >> M >> C;
    vector<int> lst(N);
    rep(i, 0, N) cin >> lst[i];
    SegmentTreeMx STmx;
    STmx.init(N, lst);
    SegmentTreeMn STmn;
    STmn.init(N, lst);
    bool flag = 0;
    rep(i, 0, N-M+1){
        if(STmx.query(i, i+M-1) - STmn.query(i, i+M-1) <= C){
            cout << i+1 << "\n";
            flag = 1;
        }
    }
    if(!flag) cout << "NONE\n";
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