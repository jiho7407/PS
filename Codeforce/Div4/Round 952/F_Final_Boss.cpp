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

ll H, N;
vector<ll> A, C;

bool check(lll m){
    lll ret = 0;
    rep(i, 0, N){
        ret += (lll)A[i] * ((m-1)/(lll)C[i]+1);
    }
    return ret >= H;
}

void solve(){
    cin >> H >> N;
    A.resize(N); C.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> C[i];
    ll ok = 1e13, ng = 0;
    
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        // cout << mid << '\n';
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}