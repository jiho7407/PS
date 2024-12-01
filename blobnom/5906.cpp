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

ll N, M, K;
string S;
ll Card[14][8];

ll calc_cur(ll turn, ll cur, bool isB_J, bool isB_B){
    ll idx = isB_J * 4 + isB_B * 2;
    cur *= (Card[turn][idx]+1);
    cur %= M;
    cur += Card[turn][idx+1];
    cur %= M;
    return cur;
}

bool BT_turn(ll turn, ll cur, bool isB_J, bool isB_B);

bool FJ_turn(ll turn, ll cur, bool isB_J){
    if(turn == N){
        return cur <= K || M-K <= cur;
    }
    bool rd = rand()&1;
    return BT_turn(turn, cur, isB_J, rd) && BT_turn(turn, cur, isB_J, !rd);
}

bool BT_turn(ll turn, ll cur, bool isB_J, bool isB_B){
    ll nxt = calc_cur(turn, cur, isB_J, isB_B);
    bool rd = rand()&1;
    return FJ_turn(turn+1, nxt, rd) || FJ_turn(turn+1, nxt, !rd);
}

void solve(){
    cin >> N >> M >> K;
    cin >> S;
    rep(i, 0, N){
        rep(j, 0, 8) cin >> Card[i][j];
    }

    ll cur = 0;
    rep(i, 0, N){
        if(FJ_turn(i, cur, true)){
            cout << 'B';
            cur = calc_cur(i, cur, true, S[i] == 'B');
        }else{
            cout << 'T';
            cur = calc_cur(i, cur, false, S[i] == 'B');
        }
    }
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