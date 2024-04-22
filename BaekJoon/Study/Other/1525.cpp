#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

unordered_map<string, int> um;
vector<int> D[9];

int main(){
    fastio();
    string board="";
    string cmd;
    for(int i = 0; i<9; i++){
        cin >> cmd;
        board += cmd;
    }
    D[0] = {1, 3};
    D[1] = {0, 2, 4};
    D[2] = {1, 5};
    D[3] = {0, 4, 6};
    D[4] = {1, 3, 5, 7};
    D[5] = {2, 4, 8};
    D[6] = {3, 7};
    D[7] = {4, 6, 8};
    D[8] = {5, 7};

    deque<pair<string, int>> Q;
    um[board] = 0;
    Q.push_back({board, 0});
    while(!Q.empty()){
        auto temp = Q.front(); Q.pop_front();
        string cur = temp.first;
        int lev = temp.second;
        int idx = cur.find('0');
        for(auto g: D[idx]){
            swap(cur[idx], cur[g]);
            if(um.find(cur) == um.end()){
                um[cur] = lev+1;
                Q.push_back({cur, lev+1});
            }
            swap(cur[idx], cur[g]);
        }
    }
    string ans = "123456780";
    if(um.find(ans) != um.end()) cout << um[ans];
    else cout << -1;
}