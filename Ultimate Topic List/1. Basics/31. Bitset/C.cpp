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

int N, M;
int A[2000][2000];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];

    bitset<2000> ret[2000];
    bitset<2000> bs[1000];
    rep(j, 0, M){
        rep(i, 0, N) bs[A[i][j]].set(i);
        rep(i, 0, N) ret[i] ^= bs[A[i][j]];
        rep(i, 0, N) bs[A[i][j]].reset(i);
    }

    int ans = 0;
    rep(i, 0, N) ans += ret[i].count();
    if(M&1) ans -= N;
    cout << ans/2 << '\n';
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