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

void solve(){
    int N, M, K; cin >> N >> M >> K;
    int cnt = min(N/(M+1), N-M*K);
    vector<int> ans(N, 0);
    int idx = 0;
    while(idx < N){
        rep(i, 0, cnt){
            if(idx+i >= N) break;
            ans[idx+i] = i;
        }
        idx += max(cnt, K);
    }
    rep(i, 0, N) cout << ans[i] << " ";
    cout << "\n";
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