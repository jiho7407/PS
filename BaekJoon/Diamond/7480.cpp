#include <bits/stdc++.h>
#include <ext/rope>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
using namespace __gnu_cxx;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


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
        return min(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, 0);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 1e9;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }

    int find_zero(int L){
        int ok = sz-1, ng = L-1;
        while(ok-ng > 1){
            int mid = (ok+ng)/2;
            if(query(L, mid) == 0) ok = mid;
            else ng = mid;
        }
        return ok;
    }
}ST;

int N, M;
rope<int> rp;

void solve(){
    cin >> N >> M;
    ST.init(N+M+10);
    rep(i, 0, M) rp.push_back(0);

    rep(i, 1, N+1){
        int x; cin >> x; x--;
        int R = ST.find_zero(x);
        ST.update(R, 1);
        rope<int> tmp = rp.substr(x, R-x);
        rp.erase(x, R-x+1);
        tmp.insert(0, i);
        rp.insert(x, tmp);
    }

    int cnt = 0, ans = 0;
    for(auto x: rp){
        ans++;
        if(x != 0) cnt++;
        if(cnt == N) break;
    }
    cout << ans << '\n';
    rep(i, 0, ans) cout << rp[i] << ' ';
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