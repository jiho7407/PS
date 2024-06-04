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

ll N, M, K;
ll A[1000005], bucket[1005], sq;

void init(){
    sq = sqrt(N);
    rep(i, 0, N){
        bucket[i/sq] += A[i];
    }
}

void update(ll idx, ll val){
    ll diff = val - A[idx];
    A[idx] = val;
    bucket[idx/sq] += diff;
}

ll query(ll l, ll r){
    ll ret = 0;
    while(l%sq && l <= r){
        ret += A[l++];
    }
    while(r%sq != sq-1 && l <= r){
        ret += A[r--];
    }
    while(l <= r){
        ret += bucket[l/sq];
        l += sq;
    }
    return ret;
}

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N) cin >> A[i];
    init();
    rep(i, 0, M+K){
        ll op, a, b; cin >> op >> a >> b;
        if(op == 1) update(a-1, b);
        else cout << query(a-1, b-1) << '\n';
    }
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