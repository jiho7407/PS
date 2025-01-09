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

ll DP[100010][2][2][3];
const ll mod = 20150523;

/*
DP[i][tight][state][sum]
i: 결정된 자릿수
tight: 현재까지의 수가 N보다 작으면 0, 같으면 1
state: 이미 3, 6, 9가 나왔는지
sum: 현재까지 자릿수의 합을 3으로 나눈 나머지
*/

bool is369(int d){
    return d == 3 || d == 6 || d == 9;
}

ll calc(string S, bool isL){
    vector<int> digit;
    for(char c:S) digit.push_back(c-'0');
    int len = digit.size();
    memset(DP, 0, sizeof(DP));

    rep(d, 0, digit[0]) DP[1][0][is369(d)][d%3]++;
    DP[1][1][is369(digit[0])][digit[0]%3]++;

    rep(i, 1, len) rep(tight, 0, 2) rep(state, 0, 2) rep(sum, 0, 3){
        rep(d, 0, 10){
            if(tight && digit[i]<d) break;
            int nt = tight && (digit[i]==d);
            int ns = state || (d == 3 || d == 6 || d == 9);
            int nsum = (sum+d)%3;
            DP[i+1][nt][ns][nsum] += DP[i][tight][state][sum];
            DP[i+1][nt][ns][nsum] %= mod;
        }
    }

    ll ret = 0;
    rep(i, 0, 2) rep(j, 0, 3) ret += DP[len][i][1][j], ret %= mod;
    rep(i, 0, 2) ret += DP[len][i][0][0], ret %= mod;

    if(!isL) return ret;

    // isL 처리
    bool flag = false;
    ll digitsum = 0;
    rep(i, 0, len){
        digitsum += digit[i];
        if(digit[i] != 0 && digit[i]%3 == 0){
            flag = true;
            break;
        }
    }
    if(digitsum%3 == 0) flag = true;
    if(flag) ret--;

    return ret;
}

void solve(){
    string L, R; cin >> L >> R;
    ll ans = calc(R, false) - calc(L, true);
    if(ans < 0) ans += mod;
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