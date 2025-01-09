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

ll DP[20][2][5];
/*
DP[i][j][k]
i: 자릿수
j: tight 여부
k: X, 2, 0, 2, 3 완성 단계
*/

void solve(){
    ll N; cin >> N;
    vector<int> digit;
    while(N) digit.push_back(N%10), N/=10;
    reverse(digit.begin(), digit.end());
    int len = digit.size();
    memset(DP, 0, sizeof(DP));
    rep(i, 0, digit[0]){
        if(i==2) DP[1][0][1]++;
        else DP[1][0][0]++;
    }
    DP[1][1][(digit[0]==2)?1:0]++;

    rep(i, 1, len) rep(tight, 0, 2) rep(k, 0, 5){
        rep(d, 0, 10){
            if(tight && digit[i]<d) break;
            int nt = tight && (digit[i]==d);
            int nk = k;
            if(k == 0 && d == 2) nk++;
            if(k == 1 && d == 0) nk++;
            if(k == 2 && d == 2) nk++;
            if(k == 3 && d == 3) nk++;
            DP[i+1][nt][nk] += DP[i][tight][k];
        }
    }

    ll ans = 0;
    rep(i, 0, 2) ans += DP[len][i][4];
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