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

int N, M, K, L;
bool DP[3010][3010];
vector<pii> problems;
bool unstable[3010];

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, K){
        int a, b; cin >> a >> b;
        problems.push_back({a, b});
    }
    cin >> L;
    rep(i, 0, L){
        int a; cin >> a;
        unstable[a] = true;
    }

    fill_n(&DP[0][0], 3010*3010, false);
    DP[0][M] = true;
    rep(i, 0, K){
        auto [g, y] = problems[i];
        rep(j, 0, N){
            if(!DP[i][j]) continue;
            if(unstable[j]) continue;
            DP[i+1][(j+g)%N] = true;
            DP[i+1][(j+y)%N] = true;
        }
    }
    if(DP[K][0]) cout << "utopia";
    else cout << "dystopia";
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