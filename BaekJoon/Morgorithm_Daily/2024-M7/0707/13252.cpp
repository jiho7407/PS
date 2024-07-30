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

map<tuple<ll, ll, ll>, ld> DP;

ld solve(ll N, ll M, ll K){
    if(DP.find({N, M, K}) != DP.end()) return DP[{N, M, K}];
    if(N == 0) return 1;
    if(K == 0) return 0;
    ld ret = 0;
    ll more = N % M;
    ret += (ld)more / M * solve(N - N/M - 1, M, K - 1); // 더 많은쪽이 날아간 경우
    ret += (ld)(M - more) / M * solve(N - N/M, M, K - 1); // 적은쪽이 날아간 경우
    return DP[{N, M, K}] = ret;
}

void solve(){
    ll N, M, K;
    cin >> N >> M >> K;
    cout << 1 - solve(N, M, K) << '\n';
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