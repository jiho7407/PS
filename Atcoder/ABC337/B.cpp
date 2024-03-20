#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int status; // 0:A, 1:B, 2:C

int main(){
    fastio();
    string S;
    cin >> S;
    status = 0;
    bool pos = true;
    for(int i = 0; i<S.length(); i++){
        char cmd;
        cmd = S[i];
        if(cmd == 'A'){
            if(status == 0) continue;
            else{
                pos = false;
                break;
            }
        }
        else if(cmd == 'B'){
            if(status == 0) status = 1;
            else if(status == 2){
                pos = false;
                break;
            }
        }
        else{
            if(status < 2) status = 2;
        }
    }
    if(pos) cout << "Yes";
    else cout << "No";
    return 0;
}