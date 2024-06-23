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

int N, M, K;
char board[201][201];

void solve(){
    cin >> N >> M >> K;
    if((K-N)%2) { cout << "No"; return; }
    if(K < N) { cout << "No"; return; }
    fill_n(&board[0][0], 201*201, '+');
    rep(i, 0, N) rep(j, 0, M) board[2*i+1][2*j+1] = 'o';
    rep(i, 0, N) rep(j, 0, M-1) board[2*i+1][2*j+2] = '|';
    rep(i, 0, N-1) rep(j, 0, M) board[2*i+2][2*j+1] = '-';

    int left = K-N;
    if(N%2 == 0 || left <= (N-1)*(M-1)){
        for(int i = 0; i < N; i += 2){
            int j = M-1;
            while(j>0){
                if(left == 0) break;
                board[2*i+1][2*j] = '.';
                board[2*i+3][2*j] = '.';
                left -= 2;
                j -= 1;
            }
            board[2*i+2][2*j+1] = '.';
            board[2*i+4][2*M-1] = '.';
        }
    }
    else{
        for(int i = 0; i < N-1; i += 2){
            int j = M-1;
            while(j>0){
                if(left == 0) break;
                board[2*i+1][2*j] = '.';
                board[2*i+3][2*j] = '.';
                left -= 2;
                j -= 1;
            }
            board[2*i+2][2*j+1] = '.';
            board[2*i+4][2*M-1] = '.';
        }
        for(int j = 0; j<M; j += 2){
            if(left == 0) break;
            board[2*N-3][2*j+2] = '|';
            board[2*N-1][2*j+2] = '.';
            board[2*N-2][2*j+1] = '.';
            board[2*N-2][2*j+3] = '.';
            left -= 2;
        }
    }

    board[0][2*M-1] = 'S';
    board[2*N][2*M-1] = 'G';

    cout << "Yes\n";
    rep(i, 0, 2*N+1){
        rep(j, 0, 2*M+1) cout << board[i][j];
        cout << '\n';
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