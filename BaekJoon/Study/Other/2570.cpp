#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 10200;
const int mxN = 105;
int N, M;
char board[mxN][mxN];
int numboard[mxN][mxN];
int AM[mx], BM[mx];
vector<int> links[mx];
bool Avisit[mx];

bool dfs(int a){
    if(Avisit[a]) return false;
    Avisit[a] = true;

    for(auto b: links[a]){
        if(!BM[b] || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}


int main(){
    fastio();
    cin >> N;
    cin >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            board[i][j] = 'X';
        }
    }
    int a, b;
    while(M--){
        cin >> a >> b;
        board[a-1][b-1] = 'O';
    }
    int x, y;
    int num = 0;
    for(int i = 0; i<=2*N-2; i++){
        num++;
        for(int j = 0; j<=i; j++){
            x = j;
            y = i-j;
            if(x<0 ||x >=N || y<0 || y>=N) continue;
            if(board[x][y] == 'O'){
                num++;
                continue;
            }
            numboard[x][y] = num;
        }
    }

    num = 0;
    for(int i = 0; i<=2*N-2; i++){
        num++;
        for(int j = 0; j<=i; j++){
            x = N-j-1;
            y = i-j;
            if(x<0 ||x >=N || y<0 || y>=N) continue;
            if(board[x][y] == 'O'){
                num++;
                continue;
            }
            links[num].push_back(numboard[x][y]);
        }
    }

    int match = 0;
    fill(AM, AM+mxN, 0);
    fill(BM, BM+mxN, 0);
    for(int i = 1; i<=num; i++){
        fill(Avisit, Avisit+num, false);
        if(dfs(i)) match++;
    }
    cout << match;
    return 0;
}