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
int DP[102][10][10][10];
int S[102], T[102];

int rot(int x){
    return (min(x, 10-x) + 2)/3;
}

int calc(int idx, int a, int b, int c){
    if(idx == N) return 0;
    if(DP[idx][a][b][c] != 1e9) return DP[idx][a][b][c];

    int &dp = DP[idx][a][b][c];
    rep(i, 0, 10){ // 3개 돌리기
        rep(j, 0, 10){ // 2개 돌리기
            rep(k, 0, 10){ // 1개 돌리기
                if((a + i + j + k) % 10 != T[idx]) continue;
                dp = min(dp, rot(i)+rot(j)+rot(k)+calc(idx+1, (b+i+j)%10, (c+i)%10, S[idx+3]));
            }
        }
    }
    // cout << idx << ' ' << a << ' ' << b << ' ' << c << ' ' << dp << '\n';
    return dp;
}

void solve(){
    cin >> N;

    string tmp;
    cin >> tmp;
    rep(i, 0, N) S[i] = tmp[i] - '0';
    cin >> tmp;
    rep(i, 0, N) T[i] = tmp[i] - '0';  

    fill_n(&DP[0][0][0][0], 102*10*10*10, 1e9);
    cout << calc(0, S[0], S[1], S[2]);
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