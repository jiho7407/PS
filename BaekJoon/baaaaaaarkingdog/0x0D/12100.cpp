#include <bits/stdc++.h>
using namespace std;

int N;
int board[25][25];
int copiedboard[25][25];
int ans = 0;

void printer(){
    cout << "\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << copiedboard[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

void move_up(int i, int j){
    if(i==0) return;
    int cmd = copiedboard[i][j];
    while(i>0){
        if(copiedboard[i-1][j] == 0){
            copiedboard[i-1][j] = cmd;
            copiedboard[i][j] = 0;
        }
        else if(copiedboard[i-1][j] == cmd){
            copiedboard[i-1][j] = cmd*2+1;
            copiedboard[i][j] = 0;
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
    int cmd = copiedboard[i][j];
    while(i<N-1){
        if(copiedboard[i+1][j] == 0){
            copiedboard[i+1][j] = cmd;
            copiedboard[i][j] = 0;
        }
        else if(copiedboard[i+1][j] == cmd){
            copiedboard[i+1][j] = cmd*2+1;
            copiedboard[i][j] = 0;
        }
        else return;
        i++;
    }
    return;
}

void move_left(int i, int j){
    if(j==0) return;
    int cmd = copiedboard[i][j];
    while(j>0){
        if(copiedboard[i][j-1] == 0){
            copiedboard[i][j-1] = cmd;
            copiedboard[i][j] = 0;
        }
        else if(copiedboard[i][j-1] == cmd){
            copiedboard[i][j-1] = cmd*2+1;
            copiedboard[i][j] = 0;
        }
        else return;
        j--;
    }
    return;
}

void move_right(int i, int j){
    if(j>=N-1) return;
    int cmd = copiedboard[i][j];
    while(j<N-1){
        if(copiedboard[i][j+1] == 0){
            copiedboard[i][j+1] = cmd;
            copiedboard[i][j] = 0;
        }
        else if(copiedboard[i][j+1] == cmd){
            copiedboard[i][j+1] = cmd*2+1;
            copiedboard[i][j] = 0;
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
            if(copiedboard[i][j]%2 == 1) copiedboard[i][j]--;
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
            temp = max(temp, copiedboard[i][j]);
        }
    }
    return temp;
}

void solver(int a){
    for(int i=0; i<N; i++){
        copy(begin(board[i]), end(board[i]), begin(copiedboard[i]));
    }
    for(int i = 0; i<5; i++){
        mover(a%4);
        a = a/4;
    }
    ans = max(ans, maxnumber());
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

    for(int i=0; i<1024; i++){
        solver(i);
    }

    cout << ans;
}