#include <bits/stdc++.h>
using namespace std;

const int mx = 2187+5;
int board[mx][mx];
int ans[3];

int paper(int N, int r, int c){
    if(N==0) return 0;
    bool allmo = true, allz = true, allpo =true;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int temp = board[r+i][c+j];
            if(temp==-1){
                allz = false;
                allpo = false;
            }
            else if(temp==0){
                allmo = false;
                allpo = false;
            }
            else{
                allmo = false;
                allz = false;
            }
        }
    }

    if(allmo) ans[0]++;
    else if(allz) ans[1]++;
    else if(allpo) ans[2]++;
    else{
        int cutter = N/3;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                paper(cutter, r+i*cutter, c+j*cutter);
            }
        }
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    paper(N, 0, 0);
    for(int i = 0; i<3; i++) cout<<ans[i]<<"\n";
}