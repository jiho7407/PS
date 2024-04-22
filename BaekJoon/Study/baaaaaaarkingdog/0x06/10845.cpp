#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<int> Q;
    int N;
    cin >> N;
    string cmd;
    int num;
    while(N--){
        cin >> cmd;
        if(cmd=="push"){
            cin >> num;
            Q.push(num);
        }
        if(cmd=="pop"){
            if(!Q.empty()){
                cout << Q.front() << "\n";
                Q.pop();
            }
            else{
                cout << "-1" << "\n";
            }
        }
        if(cmd=="size"){
            cout << Q.size() << "\n";
        }
        if(cmd == "empty"){
            if(Q.empty()){
                cout << '1' << "\n";
            }
            else{
                cout << '0' << "\n";
            }
        }
        if(cmd=="front"){
            if(!Q.empty()){
                cout << Q.front() << "\n";
            }
            else{
                cout << "-1" << "\n";
            }
        }
        if(cmd=="back"){
            if(!Q.empty()){
                cout << Q.back() << "\n";
            }
            else{
                cout << "-1" << "\n";
            }
        }
    }
}