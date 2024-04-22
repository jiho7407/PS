#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<pair<int,int>> stk;
    long long int N, cmd, ans = 0;
    cin >> N;
    cin >> cmd;
    stk.push({cmd, 0});
    for(int i = 1; i < N; i++){
        cin >> cmd;
        if(stk.top().first > cmd){
            stk.push({cmd, i});
        }
        else{
            while(!stk.empty() && stk.top().first <= cmd){
                ans += i - stk.top().second - 1;
                stk.pop();
            }
            stk.push({cmd, i});
        }
    }
    while(!stk.empty()){
                ans += N - stk.top().second - 1;
                stk.pop();
            }
    cout << ans;
}