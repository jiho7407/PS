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
    void pull(ll idx){
        tree[idx] = tree[idx<<1]+tree[idx<<1|1];
    }
    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, 0);
    }
    void update(ll i, ll x){
        ll idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) pull(idx);
    }
    ll query(ll L, ll R){
        ll left = L + sz, right = R + sz;
        ll ret = 0;
        while(left <= right){
            if((left&1)==1) ret += tree[left++];
            if((right&1)==0) ret += tree[right--];
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

ll N, S;
ll A[100000];
vector<ll> As;
map<ll, ll> mp;

void solve(){
    cin >> N >> S;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) As.push_back(A[i]);

    // 좌표 압축
    sort(As.begin(), As.end());
    As.erase(unique(As.begin(), As.end()), As.end());
    rep(i, 0, As.size()) mp[As[i]] = i+1;

    // 세그트리 초기화
    SegmentTree ST;
    ST.init(As.size()+1);
    
    // 계산
    ll ans = 0, tmp = 0;
    rep(i, 0, N){
        if(i-S >= 0){
            ST.update(mp[A[i-S]], -1);
            tmp -= ST.query(mp[A[i-S]]+1, As.size()+1);
        }
        ST.update(mp[A[i]], 1);
        tmp += ST.query(0, mp[A[i]]-1);
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
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