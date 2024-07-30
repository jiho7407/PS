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

vector<pii> ans;

void solve(){
    int N, M; cin >> N >> M;
    bool flag = false;
    if(N>M) swap(N, M), flag = true;

    rep(i, 0, N){
        int mn = (i == 0) ? 0 : i - ((i%2) ? 1 : 2);
        int mx = (i == N-1) ? M-1 : i + ((i%2) ? 1 : 2);
        mx = min(mx, M-1);
        rep(j, mn, mx+1) ans.push_back({i, j});
    }
    if(flag) for(auto &p : ans) swap(p.first, p.second);
    cout << ans.size() << '\n';
    for(auto &p : ans) cout << p.first+1 << ' ' << p.second+1 << '\n';
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