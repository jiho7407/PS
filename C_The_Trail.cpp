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

ll N, M, G;
string S;
ll board[1000][1000], board2[1000][1000];

void calc(int x, int y, int idx){
    ll rsum = 0, csum = 0;
    rep(i, 0, N) csum += board[i][y];
    rep(i, 0, M) rsum += board[x][i];

    if(idx == S.size()){
        board[x][y] = -rsum;
        return;
    }
    
    if(S[idx] == 'D'){
        board[x][y] = -rsum;
        calc(x+1, y, idx+1);
    } 
    else{
        board[x][y] = -csum;
        calc(x, y+1, idx+1);
    }
}

void solve(){
    cin >> N >> M;
    cin >> S;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    rep(i, 0, N) rep(j, 0, M) board2[i][j] = board[i][j];

    calc(0, 0, 0);

    rep(i, 0, N){
        rep(j, 0, M) cout << board[i][j] << ' ';
        cout << '\n';
    }
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