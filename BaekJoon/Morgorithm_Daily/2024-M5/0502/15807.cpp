#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, P;
int board[3001][3001];

void solve(){
    cin >> N;
    rep(i, 0, 3001) fill(board[i], board[i]+3001, 0);
    rep(i, 0, N){
        int x, y;
        cin >> x >> y;
        x += 1500; y += 1500;
        swap(x, y);
        board[x][y] += 1;

        if(x+1 < 3001) board[x+1][y] += 1;
    }

    // imos법
    rep(i, 0, 3001){
        rep(j, 0, 3001){
            if(i < 0 || i > 3000 || j < 0 || j > 3000) continue;
            if(i-1 < 0 || j-1 < 0) continue;
            board[i][j] += board[i-1][j-1];
        }
    }

    rep(i, 2, 3001) board[i][3000] += board[i-2][3000];

    rep(i, 0, 3001){
        rep(j, 0, 3001){
            if(i < 0 || i > 3000 || j < 0 || j > 3000) continue;
            if(i-1 < 0 || j+1 > 3000) continue;
            board[i][j] += board[i-1][j+1];
        }
    }
        
        

    // 테스트용 출력
    // rep(i, 2980, 3001){
    //     rep(j, 2980, 3001) cout << board[i][j] << ' ';
    //     cout << '\n';
    // }

    cin >> P;
    rep(i, 0, P){
        int x, y;
        cin >> x >> y;
        x += 1500; y += 1500;
        swap(x, y);
        cout << board[x][y] << '\n';
    }
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