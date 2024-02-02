#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[10][10];
int ans = 100;
vector<tuple<int, int, int>> cctv;

int blindSpot(){
    int blind = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == 0) blind++;
        }
    }
    return blind;
}

void printer(){
    cout << "\n";
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<pair<int,int>> combine(vector<pair<int,int>> a, vector<pair<int,int>> b){
    vector<pair<int,int>> temp;
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

vector<pair<int,int>> checkUp(int i, int j){
    int k = 1;
    vector<pair<int,int>> changed;
    while(true){
        if(i-k<0) break;
        if(board[i-k][j] == 6) break;
        if(board[i-k][j] == 0){
            board[i-k][j] = 9;
            changed.push_back({i-k, j});
        }
        k++;
    }
    return changed;
}

vector<pair<int,int>> checkDown(int i, int j){
    int k = 1;
    vector<pair<int,int>> changed;
    while(true){
        if(i+k>=N) break;
        if(board[i+k][j] == 6) break;
        if(board[i+k][j] == 0){
            board[i+k][j] = 9;
            changed.push_back({i+k, j});
        }
        k++;
    }
    return changed;
}

vector<pair<int,int>> checkLeft(int i, int j){
    int k = 1;
    vector<pair<int,int>> changed;
    while(true){
        if(j-k<0) break;
        if(board[i][j-k] == 6) break;
        if(board[i][j-k] == 0){
            board[i][j-k] = 9;
            changed.push_back({i, j-k});
        }
        k++;
    }
    return changed;
}

vector<pair<int,int>> checkRight(int i, int j){
    int k = 1;
    vector<pair<int,int>> changed;
    while(true){
        if(j+k>=M) break;
        if(board[i][j+k] == 6) break;
        if(board[i][j+k] == 0){
            board[i][j+k] = 9;
            changed.push_back({i, j+k});
        }
        k++;
    }
    return changed;
}

void btr(int cur){
    if(cur == cctv.size()){
        ans = min(ans, blindSpot());
        return;
    }
    int curx, cury, method;
    tie(curx, cury, method) = cctv[cur];
    if(method == 1){
        vector<pair<int,int>> changedChecker;
        changedChecker = checkUp(curx, cury);
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        changedChecker = checkRight(curx, cury);
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }
        
        changedChecker = checkDown(curx, cury);
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        changedChecker = checkLeft(curx, cury);
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }
    }

    else if(method == 2){
        vector<pair<int,int>> changedChecker;
        changedChecker = checkUp(curx, cury);
        changedChecker = combine(changedChecker, checkDown(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        changedChecker = checkRight(curx, cury);
        changedChecker = combine(changedChecker, checkLeft(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }
    }
    
    else if(method == 3){
        vector<pair<int,int>> changedChecker;
        changedChecker = checkUp(curx, cury);
        changedChecker = combine(changedChecker, checkRight(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        changedChecker = checkRight(curx, cury);
        changedChecker = combine(changedChecker, checkDown(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        
        changedChecker = checkDown(curx, cury);
        changedChecker = combine(changedChecker, checkLeft(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        
        changedChecker = checkLeft(curx, cury);
        changedChecker = combine(changedChecker, checkUp(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }
    }

    else if(method == 4){
        vector<pair<int,int>> changedChecker;
        changedChecker = checkUp(curx, cury);
        changedChecker = combine(changedChecker, checkRight(curx, cury));
        changedChecker = combine(changedChecker, checkDown(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        changedChecker = checkRight(curx, cury);
        changedChecker = combine(changedChecker, checkDown(curx, cury));
        changedChecker = combine(changedChecker, checkLeft(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        
        changedChecker = checkDown(curx, cury);
        changedChecker = combine(changedChecker, checkLeft(curx, cury));
        changedChecker = combine(changedChecker, checkUp(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }

        
        changedChecker = checkLeft(curx, cury);
        changedChecker = combine(changedChecker, checkUp(curx, cury));
        changedChecker = combine(changedChecker, checkRight(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }
    }


    
    else if(method == 5){
        vector<pair<int,int>> changedChecker;
        changedChecker = checkUp(curx, cury);
        changedChecker = combine(changedChecker, checkDown(curx, cury));
        changedChecker = combine(changedChecker, checkRight(curx, cury));
        changedChecker = combine(changedChecker, checkLeft(curx, cury));
        btr(cur+1);
        for(auto c : changedChecker){
            board[c.first][c.second] = 0;
        }
    }


    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int temp;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> temp;
            board[i][j] = temp;
            if(temp>= 1 && temp<=5) cctv.push_back({i, j, temp});
        }
    }

    btr(0);
    cout << ans;
}