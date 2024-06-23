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

int L, G;
vector<ll> C;
vector<ll> pfs;
ll DP[800][8001];

ll calc(int k, int i){
    return (pfs[i] - pfs[k]) * (i-k);
}

void DnC(int g, int s, int e, int rs, int re){
    if(s>e) return;
    int m = (s+e)>>1;
    DP[g][m] = 1e18;
    int idx = -1;
    rep(i, rs, min(re, m)+1){
        ll val = DP[g-1][i] + calc(i, m);
        if(DP[g][m] > val){
            DP[g][m] = val;
            idx = i;
        }
    }
    DnC(g, s, m-1, rs, idx);
    DnC(g, m+1, e, idx, re);
}

void solve(){
    cin >> L >> G;
    C.resize(L); rep(i, 0, L) cin >> C[i];
    pfs.resize(L+1); rep(i, 1, L+1) pfs[i] = pfs[i-1] + C[i-1];
    rep(i, 0, L+1) DP[0][i] = calc(0, i);
    rep(g, 1, G) DnC(g, 1, L, 0, L);
    cout << DP[G-1][L] << '\n';
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