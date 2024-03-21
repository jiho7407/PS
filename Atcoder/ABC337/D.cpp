#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int H, W, K;
vector<string> board;

int main(){
    fastio();
    cin >> H >> W >> K;
    for(int i = 0; i<H; i++){
        string line;
        cin >> line;
        board.push_back(line);
    }
    int ocnt, xcnt;
    int ans = 1234567890;

    if(K<=W){
        for(int i = 0; i<H; i++){
            ocnt = 0; xcnt = 0;
            for(int j = 0; j<K; j++){
                if(board[i][j] == 'o') ocnt++;
                if(board[i][j] == 'x') xcnt++;
            }
            if(xcnt == 0) ans = min(ans, K-ocnt);
            for(int j = K; j<W; j++){
                if(board[i][j] == 'o') ocnt++;
                if(board[i][j] == 'x') xcnt++;
                if(board[i][j-K] == 'o') ocnt--;
                if(board[i][j-K] == 'x') xcnt--;
                if(xcnt == 0) ans = min(ans, K-ocnt);
            }
        }
    }

    if(K<=H){
        for(int j = 0; j<W; j++){
            ocnt = 0; xcnt = 0;
            for(int i = 0; i<K; i++){
                if(board[i][j] == 'o') ocnt++;
                if(board[i][j] == 'x') xcnt++;
            }
            if(xcnt == 0) ans = min(ans, K-ocnt);
            for(int i = K; i<H; i++){
                if(board[i][j] == 'o') ocnt++;
                if(board[i][j] == 'x') xcnt++;
                if(board[i-K][j] == 'o') ocnt--;
                if(board[i-K][j] == 'x') xcnt--;
                if(xcnt == 0) ans = min(ans, K-ocnt);
            }
        }
    }

    if(ans==1234567890) cout << -1;
    else cout << ans;

    return 0;
}