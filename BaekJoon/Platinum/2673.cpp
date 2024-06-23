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
vector<pii> lines;
int DP[100][100];

int calc(int i, int j){
    if(DP[i][j] != -1) return DP[i][j];
    DP[i][j] = 0;
    for(auto [a, b]: lines){
        if(i<=a && b<=j) DP[i][j] = max(DP[i][j], calc(i, a-1) + calc(a+1, b-1) + calc(b+1, j) + 1);
    }
    return DP[i][j];
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, b; cin >> a >> b; a--; b--;
        if(a > b) swap(a, b);
        lines.push_back({a, b});
    }
    fill_n(&DP[0][0], 100*100, -1);
    cout << calc(0, 99);
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