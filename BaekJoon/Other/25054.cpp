#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int board[1510][1510];
vector<vector<int>> rows;
vector<vector<int>> cols;

int bin_search(vector<int> lst, int a){
    int s, e, m;
    s = 0;
    e = N-1;
    while(s<=e){
        m = (s+e)/2;
        if(lst[m]<a) s = m+1;
        else if(lst[m] > a) e = m-1;
        else return m;
    }
    return 0;
}

int main(){
    fastio();
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int cmd;
            cin >> cmd;
            board[i][j] = cmd;
        }
    }
    rows.resize(N);
    cols.resize(N);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            rows[i].push_back(board[i][j]);
            cols[j].push_back(board[i][j]);
        }
    }
    for(int i = 0; i<N; i++){
        sort(rows[i].begin(), rows[i].end());
        sort(cols[i].begin(), cols[i].end());
    }
    long long ans = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int r, c;
            r = bin_search(rows[i], board[i][j]);
            c = bin_search(cols[j], board[i][j]);
            ans += r*(N-c-1) + c*(N-r-1);
        }
    }
    cout << ans/2;
}