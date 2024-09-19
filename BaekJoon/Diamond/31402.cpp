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

int N, Q;
vector<int> links[200000];

// 0-1 Setment Tree
// 01 세그
// 화성지도 세그
struct SegmentTree01{
    ll sz = 1;
    vector<ll> tree, cnt;

    void init(ll N){
        while(sz < N) sz <<= 1;
        tree.assign(sz<<1, 0);
        cnt.assign(sz<<1, 1);

        for(ll i = sz-1; i > 0; i--) cnt[i] = cnt[i<<1] + cnt[i<<1|1];
    }

    void update(ll s, ll e, ll v){
        if(s > e) return;
        update(1, 0, sz-1, s, e, v);
    }

    void update(ll idx, ll ns, ll ne, ll s, ll e, ll v){
        if(e < ns || ne < s) return;
        if(s <= ns && ne <= e) tree[idx] += v;
        else{
            ll mid = (ns+ne)>>1;
            update(idx<<1, ns, mid, s, e, v);
            update(idx<<1|1, mid+1, ne, s, e, v);
        }
        if(tree[idx] > 0) cnt[idx] = 0;
        else if (ns != ne) cnt[idx] = cnt[idx<<1] + cnt[idx<<1|1];
        else cnt[idx] = 1;
    }

    int kth(int idx, int val){
        if(idx >= sz) return idx - sz;
        if(cnt[idx<<1] > val) return kth(idx<<1, val);
        else return kth(idx<<1|1, val - cnt[idx<<1]);
    }
}ST;

int in[200200], out[200200], rev[200200];
int eidx = 0;
void euler(int cur){
    rev[eidx] = cur;
    in[cur] = eidx++;
    for(auto nxt: links[cur]){
        euler(nxt);
    }
    out[cur] = eidx-1;
}

bool folded[200200];
void fold(int idx){
    if(in[idx] == out[idx]) return;
    if(folded[in[idx]]) ST.update(in[idx]+1, out[idx], -1);
    else ST.update(in[idx]+1, out[idx], 1);
    folded[in[idx]] ^= 1;
}

void foldall(int cur){
    for(auto nxt: links[cur]){
        foldall(nxt);
    }
    if(cur != 0) fold(cur);
}

void solve(){
    cin >> N >> Q;
    
    rep(i, 0, N){
        int cnt; cin >> cnt;
        while(cnt--){
            int v; cin >> v; v--;
            links[i].push_back(v);
        }
    }
    ST.init(N);

    euler(0);
    foldall(0);
    ST.update(0, 0, 1);
    ST.update(N, ST.sz-1, 1);
    

    int curidx = 0;
    while(Q--){
        // cout << curidx << ' ' << ST.kth(1, curidx) << ' ' << rev[ST.kth(1, curidx)]+1 << '\n';
        string S; cin >> S;
        if(S[0] == 't'){
            fold(rev[ST.kth(1, curidx)]);
            // rep(i, 0, N) cout << folded[i] << ' ';
            // cout << '\n';
        }
        else{
            int k; cin >> k;
            curidx += k;
            if(curidx < 0) curidx = 0;
            if(curidx >= ST.cnt[1]) curidx = ST.cnt[1] - 1;
            cout << rev[ST.kth(1, curidx)]+1 << '\n';
        }
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