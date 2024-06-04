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

ll N;
vector<pll> label;
ll DP[10001]; // DP[i]: label[i-1].first에 오른변 딱 대고 직선 최대

ll topdown(int idx){
    if(idx > N) return 0;
    if(DP[idx] != -1) return DP[idx];
    DP[idx] = 1;

    ll cur;
    if(idx == 0) cur = -10000000;
    else cur = label[idx-1].first;

    ll cnt;
    if(idx == 0) cnt = 0;
    else cnt = 1;

    rep(i, idx+1, N+1){
        auto [np, nw] = label[i-1];
        if(cur + nw <= np) DP[idx] = max(DP[idx], topdown(i) + cnt);

        if(cur <= np && np <= cur+nw) cnt++;
        cur += nw;
    }
    DP[idx] = max(DP[idx], cnt);
    return DP[idx];
}

void solve(){
    cin >> N;
    label.resize(N);
    rep(i, 0, N) cin >> label[i].first;
    rep(i, 0, N) cin >> label[i].second;
    sort(label.begin(), label.end());

    fill(DP, DP + 10001, -1);
    ll ans = N;
    rep(i, 0, N+1) ans = min(ans, N - topdown(i));
    cout << ans << "\n";
    // cout << N - topdown(0) << "\n";
    // rep(i, 0, N+1) cout << DP[i] << " ";
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