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

ll N, M;
int DP[100000], tmp[100000], ans;
vector<int> S;

void solve(){
    cin >> N >> M;
    S.resize(N);
    rep(i, 0, N) cin >> S[i];
    fill(DP, DP+M, -1);
    DP[0] = 0;
    ans = 0;
    rep(i, 0, N){
        fill(tmp, tmp+M, -1);
        rep(j, 0, M){
            if(DP[j] == -1) continue;
            tmp[j] = max(tmp[j], DP[j]);
            tmp[(j+S[i])%M] = max(tmp[(j+S[i])%M], DP[j]+1);
        }
        ans = max(ans, tmp[0]);
        rep(j, 0, M) DP[j] = tmp[j];
    }
    cout << ans << '\n';

    S.clear();    
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