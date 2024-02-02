#include <bits/stdc++.h>
using namespace std;

int getminrotate(deque<int>& DQ, int x){
    int len = DQ.size();
    int leftrot, rightrot;
    for(int i = 0; i < len; i++){
        if(DQ[i] == x){
            leftrot = i;
            break;
        }
    }
    rightrot = len - leftrot;
    if(leftrot < rightrot){
        for(int i = 0; i < leftrot; i++){
            DQ.push_back(DQ.front());
            DQ.pop_front();
        }
        DQ.pop_front();
        return leftrot;
    }
    else{
        for(int i = 0; i < rightrot; i++){
            DQ.push_front(DQ.back());
            DQ.pop_back();
        }
        DQ.pop_front();
        return rightrot;
    }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);
  deque<int> DQ;
  int N, M, ans = 0, temp;
  cin >> N >> M;
  for(int i = 1; i<=N; i++){
    DQ.push_back(i);
  }
  for(int i = 1; i<=M; i++){
    cin >> temp;
    ans += getminrotate(DQ, temp);
  }
  cout << ans;
}