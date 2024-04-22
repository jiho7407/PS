#include <bits/stdc++.h>
using namespace std;

int N;
int board[10][10];
int halfans = 0;
int ans = 0;
vector<pair<int,int>> v;

bool onLine(pair<int, int> spot1, pair<int, int> spot2){
    if(abs(spot1.first - spot2.first) == abs(spot1.second - spot2.second)) return false;
    return true;
}

pair<int, int> position(int k){
    return {k/N, k%N};
}

void btr(int num, int cnt){ //first : 0,0 시작칸
    int plusnum = 0;
    if(N%2 == 1) plusnum = 2;
    else{
        int cal = N - num%N;
        if(cal >= 3) plusnum = 2;
        else if(cal%2 == 0) plusnum = 3;
        else plusnum = 1;
    }
    if(num >= N*N){
        halfans = max(halfans, cnt);
        return;
    }
    pair<int, int> temp = position(num);
    if(board[temp.first][temp.second] == 0){
        btr(num+plusnum, cnt);
        return;
    }
    if(v.empty()){
        v.push_back(temp);
        btr(num+plusnum, cnt+1);
        v.pop_back();
        btr(num+plusnum, cnt);
        return;
    }
    bool ispossible = true;
    for(auto c : v){
        if(!onLine(c, temp)) ispossible = false;
    }
    if(ispossible){
        v.push_back(temp);
        btr(num+plusnum, cnt+1);
        v.pop_back();
        btr(num+plusnum, cnt);
        return;
    }
    btr(num+plusnum, cnt);
    return;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    btr(0, 0);
    ans += halfans;
    halfans = 0;
    btr(1, 0);
    ans += halfans;
    cout << ans;
}