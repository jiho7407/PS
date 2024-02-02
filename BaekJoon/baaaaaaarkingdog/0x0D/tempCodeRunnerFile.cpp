#include <bits/stdc++.h>
using namespace std;

int N;
int board[25][25];
int ans = 0;

void printer(){
    cout << "\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

void move_up(int i, int j){
    if(i==0) return;
    int cmd = board[i][j];
    while(i>0){
        if(board[i-1][j] == 0){
            board[i-1][j] = cmd;
            board[i][j] = 0;
        }
        else if(board[i-1][j] == cmd){
            board[i-1][j] = cmd*2+1;
            board[i][j] = 0;
        }
        else{
            return;
        }
        i--;
    }
    return;
}

void move_down(int i, int j){
    if(i>=N-1) return;
    int cmd = board[i][j];
    while(i<N-1){
        if(board[i+1][j] == 0){
            board[i+1][j] = cmd;
            board[i][j] = 0;
        }
        else if(board[i+1][j] == cmd){
            board[i+1][j] = cmd*2+1;
            board[i][j] = 0;
        }
        else return;
        i++;
    }
    return;
}

void move_left(int i, int j){
    if(j==0) return;
    int cmd = board[i][j];
    while(j>0){
        if(board[i][j-1] == 0){
            board[i][j-1] = cmd;
            board[i][j] = 0;
        }
        else if(board[i][j-1] == cmd){
            board[i][j-1] = cmd*2+1;
            board[i][j] = 0;
        }
        else return;
        j--;
    }
    return;
}

void move_right(int i, int j){
    if(j>=N-1) return;
    int cmd = board[i][j];
    while(j<N-1){
        if(board[i][j+1] == 0){
            board[i][j+1] = cmd;
            board[i][j] = 0;
        }
        else if(board[i][j+1] == cmd){
            board[i][j+1] = cmd*2+1;
            board[i][j] = 0;
        }
        else return;
        j++;
    }
    return;
}

void board_up(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            move_up(i, j);
        }
    }
    return;
}

void board_down(){
    for(int i = N-1; i>=0; i--){
        for(int j = 0; j<N; j++){
            move_down(i, j);
        }
    }
    return;
}

void board_left(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            move_left(i, j);
        }
    }
    return;
}

void board_right(){
    for(int i = 0; i<N; i++){
        for(int j=N-1; j>=0; j--){
            move_right(i, j);
        }
    }
    return;
}

void to_origin(){
    for(int i=0; i<N; i++){
        for(int j =0; j<N; j++){
            if(board[i][j]%2 == 1) board[i][j]--;
        }
    }
    return;
}

void mover(int a){
    switch(a){
        case 0: board_up(); break;
        case 1: board_right(); break;
        case 2: board_down(); break;
        case 3: board_left(); break;
    }
    to_origin();
    return;
}

int maxnumber(){
    int temp = 0;
    for(int i=0; i<N; i++){
        for(int j =0; j<N; j++){
            temp = max(temp, board[i][j]);
        }
    }
    return temp;
}

void btr(int a){
    if(a == 5){
        ans = max(ans, maxnumber());
        return;
    }
    for(int i = 0; i<4; i++){
        mover(i);
        btr(a+1);
    }
    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    btr(0);

    cout << ans;
}