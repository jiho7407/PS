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

struct SegmentTree{
    vector<pii> tree; // mn, idx;
    int sz;

    pii pull(pii a, pii b){
        if(a.first < b.first) return a;
        if(a.first > b.first) return b;
        return {a.first, min(a.second, b.second)};
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
        rep(i, 0, N) tree[sz+i] = {1e9, i};
    }
    
    void set(int i, int x){
        tree[sz+i] = {x, i};
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void kill(int i){
        int idx = sz + i;
        tree[idx] = {INT_MAX, i};
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }

    pii query(int L, int R){
        int left = L + sz, right = R + sz;
        pii ret = {INT_MAX, -1};
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}mnST;

struct SegmentTree2{
    vector<pii> tree; // mx, idx;
    int sz;

    pii pull(pii a, pii b){
        if(a.first > b.first) return a;
        if(a.first < b.first) return b;
        return {a.first, min(a.second, b.second)};
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
        rep(i, 0, N) tree[sz+i] = {0, i};
    }
    
    void set(int i, int x){
        tree[sz+i] = {x, i};
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void kill(int i){
        int idx = sz + i;
        tree[idx] = {0, i};
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }

    pii query(int L, int R){
        int left = L + sz, right = R + sz;
        pii ret = {0, -1};
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}mxST;

int N;
vector<int> idxs[300001];
set<int> lasts;

void solve(){
    cin >> N;
    mnST.init(N);
    mxST.init(N);
    rep(i, 0, N+1) idxs[i].clear();
    lasts.clear();

    rep(i, 0, N){
        int x; cin >> x;
        mnST.set(i, x);
        mxST.set(i, x);
        idxs[x].push_back(i);
    }
    mnST.build();
    mxST.build();
    rep(i, 1, N+1) if(!idxs[i].empty()) lasts.insert(idxs[i].back());

    // for(auto s: lasts) cout << s << ' ';
    // cout << '\n';

    cout << lasts.size() << '\n';
    int cnt = 0;
    int L = 0, R = N-1;
    while(1){
        if(lasts.empty()) break;
        R = *lasts.begin();
        // cout << "cnt: " << cnt << " L: " << L << " R: " << R << endl;
        if(cnt%2 == 0){ // 홀수번째, 최댓값 출력
            pii mx = mxST.query(L, R);
            // cout << "mx: " << mx.first << ' ' << mx.second << endl;
            cout << mx.first << ' ';
            lasts.erase(idxs[mx.first].back());
            for(auto idx: idxs[mx.first]){
                mnST.kill(idx);
                mxST.kill(idx);
            }
            cnt++;
            L = mx.second + 1;
        }else{
            pii mn = mnST.query(L, R);
            cout << mn.first << ' ';
            lasts.erase(idxs[mn.first].back());
            for(auto idx: idxs[mn.first]){
                mnST.kill(idx);
                mxST.kill(idx);
            }
            cnt++;
            L = mn.second + 1;
        }
    }
    cout << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}