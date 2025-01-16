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

ll get_sum(ll N){
    ll ret = 0;
    ll blk = (N-1)/3;
    ret += 3*blk*(blk+1)/2 - blk;
    ll start = (N-1)/3*3;
    while(start < N){
        if(start%3 == 1) ret += start/3;
        else ret += start/3+1;
        start++;
    }
    return ret;
}

ll calc(ll N){
    if(N == 1) return 1;

    ll ok = 0, ng = 1e9;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(get_sum(mid) < N) ok = mid;
        else ng = mid;
    }

    ll left = N - get_sum(ok);
    ll ret = ok*(ok+1)/2;
    if(ok%3 == 0) return ret + left*3 - 2;
    else if(ok%3 == 1) return ret + left*3;
    else return ret + left*3 - 1;
}

void solve(){
    ll N; cin >> N;
    cout << calc(N) << '\n';
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