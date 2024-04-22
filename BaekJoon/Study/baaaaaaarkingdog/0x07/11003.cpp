#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    deque<pair<int,int>> DQ;
    int N, L, temp;
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> temp;
        if(DQ.empty()){
            DQ.push_back({temp, i});
        }
        else{
            while(!DQ.empty() && i - DQ.front().second >= L){
                DQ.pop_front();
            }
            while(!DQ.empty() && DQ.back().first >= temp){
                DQ.pop_back();
            }
            DQ.push_back({temp, i});
        }
        cout << DQ.front().first << " ";
    }
}