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

int N;
pii nxt[1000];
int DP[100][1000]; // DP[i][j] = i턴이 남았을때, j번째 사람이 지목되어있으면 이길 수 있나?

bool calc(int K, int idx){
    if(DP[K][idx] != -1) return DP[K][idx];

    auto [a, b] = nxt[idx];
    int &ret = DP[K][idx];

    if(idx == 0){
        if(calc(K-1, a) || calc(K-1, b)) return ret = 1;
        else return ret = 0;
    }
    else{
        if(calc(K-1, a) && calc(K-1, b)) return ret = 1;
        else return ret = 0;
    }
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        cin >> nxt[i].first >> nxt[i].second;
        nxt[i].first--;
        nxt[i].second--;
    }

    rep(i, 0, 100) rep(j, 0, N) DP[i][j] = -1;
    rep(i, 0, N) DP[1][i] = 1;
    rep(i, 0, N){
        auto [a, b] = nxt[i];
        if(a == 0 || b == 0) DP[1][i] = 0;
    }
    rep(i, 10, 100){
        if(calc(i, 0) == 1){
            cout << i;
            return;
        }
    }
    cout << -1;
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