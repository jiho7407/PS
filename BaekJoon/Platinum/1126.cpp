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

// int N;
// vector<int> blocks;
// int DP[51][500001]; // DP[i][j] = i번째블럭까지 이용했고, 높이차가 j일때 긴 탑의 최대 높이

// void solve(){
//     cin >> N;
//     blocks.resize(N);
//     rep(i, 0, N) cin >> blocks[i];
//     fill_n(&DP[0][0], 51*500001, -1);
//     DP[0][0] = 0;
//     rep(i, 0, N) rep(j, 0, 500001){
//         if(DP[i][j] == -1) continue;
//         int block = blocks[i];
//         DP[i+1][j] = max(DP[i+1][j], DP[i][j]); // 아무것도 안함
//         DP[i+1][j+block] = max(DP[i+1][j+block], DP[i][j] + block); // 긴 탑에 추가
//         if(j > block) DP[i+1][j-block] = max(DP[i+1][j-block], DP[i][j]); // 짧은탑에 추가, 관계 그대로
//         else DP[i+1][block-j] = max(DP[i+1][block-j], DP[i][j] + block - j); // 짧은탑에 추가, 관계 바뀜
//     }
//     if(DP[N][0] == 0) cout << -1;
//     else cout << DP[N][0];
// }

int N;
vector<int> blocks;

void solve(){
    cin >> N;
    blocks.resize(N);
    rep(i, 0, N) cin >> blocks[i];
    int sum = 0;
    rep(i, 0, N) sum += blocks[i];
    vector<int> DP(sum+1, -1);
    DP[0] = 0;
    for(auto block: blocks){
        vector<int> tmp(sum+1, -1);
        rep(i, 0, sum+1){
            if(DP[i] == -1) continue;
            tmp[i] = max(tmp[i], DP[i]);
            tmp[i+block] = max(tmp[i+block], DP[i] + block);
            if(i > block) tmp[i-block] = max(tmp[i-block], DP[i]);
            else tmp[block-i] = max(tmp[block-i], DP[i] + block - i);
        }
        DP = tmp;
    }
    if(DP[0] == 0) cout << -1;
    else cout << DP[0];
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}