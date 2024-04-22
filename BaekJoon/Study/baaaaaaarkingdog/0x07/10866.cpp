#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);
  deque<int> DQ;
  int N;
  cin >> N;
  string cmd;
  int temp;
  while(N--){
    cin >> cmd;
    if(cmd == "push_front"){
        cin >> temp;
        DQ.push_front(temp);
    }
    if(cmd == "push_back"){
        cin >> temp;
        DQ.push_back(temp);
    }
    if(cmd == "pop_front"){
        if(DQ.empty()){
           cout << -1 << "\n";
        }
        else{
            cout << DQ.front() << "\n";
            DQ.pop_front();
        }
    }
    if(cmd == "pop_back"){
        if(DQ.empty()){
           cout << -1 << "\n";
        }
        else{
            cout << DQ.back() << "\n";
            DQ.pop_back();
        }
    }
    if(cmd == "size"){
        cout << DQ.size() << "\n";
    }
    if(cmd == "empty"){
        if(DQ.empty()){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    if(cmd == "front"){
        if(DQ.empty()){
           cout << -1 << "\n";
        }
        else{
            cout << DQ.front() << "\n";
        }
    }
    if(cmd == "back"){
        if(DQ.empty()){
           cout << -1 << "\n";
        }
        else{
            cout << DQ.back() << "\n";
        }
    }    
  }
}