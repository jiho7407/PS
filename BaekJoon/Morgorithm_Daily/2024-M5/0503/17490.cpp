#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SegmentTree{
    vector<ll> tree;
    ll sz;
    void init(ll N, vector<ll>& lst){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, 1e9);
        for(ll i = 0; i < N; i++){
            tree[sz+i] = lst[i];
        }
        for(ll i = sz-1; i > 0; i--){
            tree[i] = min(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = min(tree[idx<<1], tree[idx<<1|1]);
        }
    }
    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = 1e9;
        while(left <= right){
            if((left&1)==1) ret = min(ret, tree[left++]);
            if((right&1)==0) ret = min(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

ll mxN = 1e6;
ll N, M, K;
vector<ll> S;
vector<ll> cuts;


void solve(){
    cin >> N >> M >> K;
    S.resize(N);
    rep(i, 0, N) cin >> S[i];
    SegmentTree ST;
    ST.init(N, S);
    rep(i, 0, M){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a, b);
        if(a == 0 && b == N-1) swap(a, b);
        cuts.push_back(a);
    }
    if(M <= 1) {
        cout << "YES";
        return;
    }
    sort(cuts.begin(), cuts.end());
    ll tmp = 0;
    rep(i, 1, M){
        tmp += ST.query(cuts[i-1]+1, cuts[i]);
    }
    if(cuts[M-1] == N-1) tmp += ST.query(0, cuts[0]);
    else tmp += min(ST.query(0, cuts[0]), ST.query(cuts[M-1]+1, N-1));
    if(tmp <= K) cout << "YES";
    else cout << "NO";
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}