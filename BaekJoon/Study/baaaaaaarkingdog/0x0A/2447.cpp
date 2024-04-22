#include <bits/stdc++.h>
using namespace std;

string board[10000];

int star(int N, int r){
    if(N==3){
        board[r]   += "***";
        board[r+1] += "* *";
        board[r+2] += "***";
        return 0;
    }
    int third = N/3;
    for(int i = 0; i<3; i++){
        star(third, r+third*i);
    }
    star(third, r);
    for(int i = 0; i<third; i++){
        for(int j=0; j<third; j++){
            board[r+third+i] += " ";
        }
    }
    star(third, r+third*2);
    for(int i = 0; i<3; i++){
        star(third, r+third*i);
    }
    return 0;
}

int main(){
    int N;
    cin >> N;
    fill(board, board+N, "");
    star(N, 0);
    for(int i = 0; i<N; i++){
        cout << board[i] << "\n";
    }
}