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

ll DP[20][10][2][2];

ll calc(ll N){
    /*
    DP를 이용해서 계산
    DP[i][j][k][l]
    i: 현재까지 결정한 자릿수
    j: 0이 아닌 첫번째 숫자가 무엇인지
    k: 현재 숫자가 x보다 작은것이 확정 되었는지 여부 (strict)
    l: 앞에서부터 0이 계속 이어지고 있는지 여부 (nonzero)
    */
    string S = to_string(N);
    vector<int> digit;
    for(auto c : S) digit.push_back(c-'0');
    int n = digit.size();
    fill_n(&DP[0][0][0][0], 20*10*2*2, 0);

    DP[1][0][1][0] = 1; // 맨 앞 숫자 0으로 결정
    for(int i = 1; i < digit[0]; i++) DP[1][i][1][1] = 1;
    DP[1][digit[0]][0][1] = 1;

    rep(i, 1, n) rep(j, 0, 10) rep(strict, 0, 2) rep(nonzero, 0, 2){
        rep(k, 0, 10){
            if(nonzero && j <= k) continue; // 맨앞 숫자가 strict하게 커야됨
            if(!strict && digit[i] < k) continue; // 현재 숫자가 N보다 작아야됨
            int sn = (strict || k < digit[i]);
            int zn = (nonzero || k > 0);
            int jn = (!nonzero && k != 0) ? k : j;
            DP[i+1][jn][sn][zn] += DP[i][j][strict][nonzero];
        }
    }
    ll ret = 0;
    rep(j, 0, 10) rep(strict, 0, 2) ret += DP[n][j][strict][1];
    return ret;
}


void solve(){
    ll L, R; cin >> L >> R;
    cout << calc(R) - calc(L-1) << '\n';
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