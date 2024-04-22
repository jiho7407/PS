#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, temp;
    cin >> N;
    stack<pair<int, int>> stk;
    int arr[N];
    fill(arr, arr+N, 0);
    cin >> temp;
    stk.push({temp, 1});
    arr[0] = 0;
    for(int i = 1; i < N; i++){
        cin >> temp;
        while(!stk.empty() && stk.top().first < temp){
            stk.pop();
        }
        if(!stk.empty()){
            arr[i] = stk.top().second;
        }
        stk.push({temp, i+1});
    }
    for(int i = 0; i<N; i++){
        cout << arr[i] << " ";
    }
}