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

const int mod = 9901;
int N, M;
int DP[14*14+1][1<<14];

int topDown(int cur, int state){
    if(cur == 0) return (state == 0); // 모두 채워진 경우
    if(DP[cur][state] != -1) return DP[cur][state];

    DP[cur][state] = 0;
    if(state & 1) return DP[cur][state] = topDown(cur-1, state >> 1); // 현재 칸이 채워진경우
    
    // 세로로 채우기
    int nxtstate = (state >> 1) + (1<<(M-1)); // 한칸 땡기고 윗칸먹기
    DP[cur][state] += topDown(cur-1, nxtstate);
    // 앞 칸이 비어있는 경우 가로로 채우기
    if(!(state & 2) && ((cur-1)%M != 0)) DP[cur][state] += topDown(cur-2, state >> 2); // 두칸 땡기기

    return DP[cur][state]%mod;
}

void solve(){
    cin >> N >> M;
    fill_n(&DP[0][0], (14*14+1)*(1<<14), -1);
    cout << topDown(N*M, 0);
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