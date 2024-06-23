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

int N;
vector<ll> A;
vector<ll> tmp;

void dfs(int cur, int i, int j, int d){ // 높이가 i이상 j이하인애들 다 넣기
    if(cur > N) return;
    dfs(cur<<1, i, j, d+1);
    if(i <= d && d <= j) tmp.push_back(A[cur]);
    dfs(cur<<1|1, i, j, d+1);
}

ll calc(int i, int j){
    tmp.clear();
    dfs(1, i, j, 0);
    vector<ll> DP(tmp.size());
    ll mx = tmp[0];
    DP[0] = tmp[0];
    rep(k, 1, tmp.size()){ DP[k] = max(DP[k-1]+tmp[k], tmp[k]); mx = max(mx, DP[k]); }
    return mx;
}

void solve(){
    cin >> N;
    A.resize(N+1);
    rep(i, 1, N+1) cin >> A[i];
    int sz = 1, tmpN = N;
    while(tmpN > 1){
        tmpN >>= 1;
        sz++;
    }
    ll ans = -1e18;
    rep(i, 0, sz) rep(j, i, sz) ans = max(ans, calc(i, j));
    cout << ans;
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