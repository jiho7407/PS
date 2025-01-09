#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

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

const int SZ = 500;
int R, C, M;
string board[500];
string S;
bitset<SZ> sea[500];
bitset<SZ> DP[500][5001];
bitset<SZ> cutter;
bool visited[500][5001];

bitset<SZ> calc(int r, int idx){
    if(r < 0 || r >= R) return bitset<SZ>();
    if(idx == 0) return sea[r];
    if(visited[r][idx]) return DP[r][idx];

    visited[r][idx] = 1;
    bitset<SZ> &ret = DP[r][idx];
    if(S[idx-1] == 'N' || S[idx-1] == '?') ret |= calc(r+1, idx-1);
    if(S[idx-1] == 'S' || S[idx-1] == '?') ret |= calc(r-1, idx-1);
    if(S[idx-1] == 'E' || S[idx-1] == '?') ret |= calc(r, idx-1) << 1;
    if(S[idx-1] == 'W' || S[idx-1] == '?') ret |= calc(r, idx-1) >> 1;
    ret &= sea[r];
    return ret;
}

void solve(){
    cin >> R >> C >> M;
    rep(i, 0, R) cin >> board[i];
    cin >> S;
    rep(i, 0, R) rep(k, 0, M+1) visited[i][k] = 0;
    rep(i, 0, R) rep(j, 0, C) sea[i][j] = board[i][j] == '.';
    rep(i, 0, C) cutter[i] = 1;

    int ans = 0;
    rep(i, 0, R) ans += calc(i, M).count();
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