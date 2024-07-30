#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int A[500000];

bool cmp(int a, int b){
    return a > b;
}

struct SegmentTree{
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
}ST;

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    sort(A, A+N, cmp);
    ST.init(N);
    rep(i, 0, N-4){
        ST.set(i, -A[i] + A[i+1] + A[i+2] + A[i+3] + A[i+4]);
    }
    ST.build();
    int ans = -1;
    rep(i, 1, N-5){
        int p1, p2, p3;
        p2 = i;
        if(ST.query(i+1, N-5) <= A[p2]) continue;
        int ok = N-4, ng = i;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(ST.query(i+1, mid) > A[p2]) ok = mid;
            else ng = mid;
        }
        p3 = ok;

        if(A[i-1] >= A[p2] + A[p3]) continue;
        ok = i-1, ng = -1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(A[mid] < A[p2] + A[p3]) ok = mid;
            else ng = mid;
        }
        p1 = ok;
        // cout << p1 << ' ' << p2 << ' ' << p3 << '\n';
        ans = max(ans, A[p1] + A[p2] + A[p3] + A[p3+1] + A[p3+2] + A[p3+3] + A[p3+4]);
    }
    cout << ans << '\n';
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