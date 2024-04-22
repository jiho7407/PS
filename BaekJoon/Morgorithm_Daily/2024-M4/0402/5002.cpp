#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int X;
string S;
int Mcnt = 0, Wcnt = 0;

bool pos(char cmd){
    if(cmd == 'M' && abs(Mcnt+1 - Wcnt) <= X){Mcnt++; return true;}
    if(cmd == 'W' && abs(Wcnt+1 - Mcnt) <= X){Wcnt++; return true;}
    return false;
}

void solve(){
    cin >> X >> S;
    char wait = 'N';
    for(int i = 0; i<S.size(); i++){
        char cmd = S[i];
        if(wait != 'N' && pos(wait)){
            wait = 'N';
        }
        if(pos(cmd)) continue;
        else if(wait == 'N') wait = cmd;
        else break;
    }
    cout << Mcnt+Wcnt;
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}