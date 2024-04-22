#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int sticker[105][20][20];
pair<int,int> sizes[105];
int board[100][100];

void printer(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool tryUp(int cur, int x, int y){
    bool isable = true;
    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j] == 1 && board[x+i][y+j] == 1) return false;
        }
    }
    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j]) board[x+i][y+j] = 1;
        }
    }
    return true;
}

bool tryRight(int cur, int x, int y){
    bool isable = true;
    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j] == 1 && board[x+j][y+sizes[cur].first-1-i] == 1) return false;
        }
    }

    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j] == 1) board[x+j][y+sizes[cur].first-1-i] = 1;
        }
    }
    return true;
}

bool tryDown(int cur, int x, int y){
    bool isable = true;
    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j] == 1 && board[x+sizes[cur].first-1-i][y+sizes[cur].second-1-j] == 1) return false;
        }
    }
    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j]) board[x+sizes[cur].first-1-i][y+sizes[cur].second-1-j] = 1;
        }
    }
    return true;
}

bool tryLeft(int cur, int x, int y){
    bool isable = true;
    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j] == 1 && board[x+sizes[cur].second-1-j][y+i] == 1) return false;
        }
    }

    for(int i = 0; i<sizes[cur].first; i++){
        for(int j = 0; j<sizes[cur].second; j++){
            if(sticker[cur][i][j] == 1) board[x+sizes[cur].second-1-j][y+i] = 1;
        }
    }
    return true;
}

void stick(int cur){
    int xsize = sizes[cur].first;
    int ysize = sizes[cur].second;
    for(int i = 0; i<=N-xsize; i++){
        for(int j = 0; j<=M-ysize; j++){
            if(tryUp(cur, i, j)) return;
        }
    }
    for(int i = 0; i<=N-ysize; i++){
        for(int j = 0; j<=M-xsize; j++){
            if(tryRight(cur, i, j)) return;
        }
    }
    for(int i = 0; i<=N-xsize; i++){
        for(int j = 0; j<=M-ysize; j++){
            if(tryDown(cur, i, j)) return;
        }
    }
    for(int i = 0; i<=N-ysize; i++){
        for(int j = 0; j<=M-xsize; j++){
            if(tryLeft(cur, i, j)) return;
        }
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 0; i<K; i++){
        int row, col;
        cin >> row >> col;
        sizes[i] = {row, col};
        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                cin >> sticker[i][r][c];
            }
        }
    }
    
    for(int i = 0; i<N; i++){
        fill(board[i], board[i]+M, 0);
    }

    for(int i = 0; i<K; i++){
        stick(i);
    }
    // printer();
    int ans = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j]) ans++;
        }
    }
    cout << ans;
}