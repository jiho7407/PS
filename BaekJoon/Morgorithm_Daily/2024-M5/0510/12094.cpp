#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxcnt = 10;
int N, ans, board[20][20];

void left(){
    rep(i, 0, N){
        queue<int> tmp;
        rep(j, 0, N){
            if (board[i][j]) tmp.push(board[i][j]), board[i][j] = 0;
        }
        int idx = 0;
        while(tmp.size()){
            int cur = tmp.front(); tmp.pop();
            if(tmp.size() && cur == tmp.front()){
                cur *= 2;
                tmp.pop();
            }
            board[i][idx++] = cur;
        }
    }
}

void right(){
    rep(i, 0, N){
        queue<int> tmp;
        for(int j = N - 1; j >= 0; j--){
            if (board[i][j]) tmp.push(board[i][j]), board[i][j] = 0;
        }
        int idx = N - 1;
        while(tmp.size()){
            int cur = tmp.front(); tmp.pop();
            if(tmp.size() && cur == tmp.front()){
                cur *= 2;
                tmp.pop();
            }
            board[i][idx--] = cur;
        }
    }
}

void up(){
    rep(j, 0, N){
        queue<int> tmp;
        rep(i, 0, N){
            if (board[i][j]) tmp.push(board[i][j]), board[i][j] = 0;
        }
        int idx = 0;
        while(tmp.size()){
            int cur = tmp.front(); tmp.pop();
            if(tmp.size() && cur == tmp.front()){
                cur *= 2;
                tmp.pop();
            }
            board[idx++][j] = cur;
        }
    }   
}

void down(){
    rep(j, 0, N){
        queue<int> tmp;
        for(int i = N - 1; i >= 0; i--){
            if (board[i][j]) tmp.push(board[i][j]), board[i][j] = 0;
        }
        int idx = N - 1;
        while(tmp.size()){
            int cur = tmp.front(); tmp.pop();
            if(tmp.size() && cur == tmp.front()){
                cur *= 2;
                tmp.pop();
            }
            board[idx--][j] = cur;
        }
    }
}

void move(int d){
    if (d == 0) left();
    else if (d == 1) right();
    else if (d == 2) up();
    else down();
}

int getmx(){
    int mx = 0;
    rep(i, 0, N) rep(j, 0, N) mx = max(mx, board[i][j]);
    return mx;
}

void btr(int cnt){
    if(cnt == mxcnt){
        ans = max(ans, getmx());
        return;
    }
    if(ans >= (1 << (mxcnt - cnt)) * getmx()) return;
    
    int cur[20][20];
    memcpy(cur, board, sizeof(cur));

    rep(d, 0, 4){
        move(d);
        
        bool flag = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(cur[i][j] != board[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) continue;
        btr(cnt + 1);
        if(d == 3) break;
        memcpy(board, cur, sizeof(board));
    }
    return;
}

void solve(){
    cin >> N;
    rep(i, 0, N) rep(j, 0, N) cin >> board[i][j];
    ans = getmx();
    btr(0);
    cout << ans << "\n";
    return;
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