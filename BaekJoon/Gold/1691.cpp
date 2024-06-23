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

int N, W, H;
int DP[601][601];

int topDown(int w, int h){
    if(DP[w][h] != -1) return DP[w][h];
    DP[w][h] = w*h;
    rep(i, 1, w-i+1) DP[w][h] = min(DP[w][h], topDown(i, h) + topDown(w-i, h));
    rep(i, 1, h-i+1) DP[w][h] = min(DP[w][h], topDown(w, i) + topDown(w, h-i));
    return DP[w][h];
}

void solve(){
    cin >> W >> H >> N; 
    fill_n(&DP[0][0], 601*601, -1);
    rep(i, 0, N){
        int x, y; cin >> x >> y;
        DP[x][y] = 0;
    }
    DP[0][0] = 0;
    cout << topDown(W, H) << '\n';
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