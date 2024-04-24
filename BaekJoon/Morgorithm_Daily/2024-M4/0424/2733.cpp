#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxidx = 32768, mxNum = 256;
int arr[mxidx], pairidx[mxidx];


void solve(){
    fill(arr, arr+mxidx, 0);
    fill(pairidx, pairidx+mxidx, -1);

    // 입력
    string program, input;
    program = "";
    while(1){
        string temp;
        getline(cin, temp);
        if(temp == "end") break;
        for(auto c: temp){
            if(c == '%') break;
            if(c == ' ') continue;
            program += c;
        }
    }

    // 괄호 검사
    int idx = 0;
    stack<int> stk;
    for(auto c: program){
        if(c == '[') stk.push(idx);
        if(c == ']'){
            if(stk.empty()) {cout << "COMPILE ERROR\n"; return;}
            int tmp = stk.top(); stk.pop();
            if(program[tmp] == ']') {cout << "COMPILE ERROR\n"; return;}
            pairidx[tmp] = idx;
            pairidx[idx] = tmp;
        }
        idx++;
    }
    if(!stk.empty()) {cout << "COMPILE ERROR\n"; return;}

    // 구현
    idx = 0;
    int pt = 0;
    string ans = "";
    while(1){
        if(idx >= program.size()) break;
        char cmd = program[idx];
        if(cmd == '>') pt = (pt + 1) % mxidx;
        if(cmd == '<') pt = (pt - 1 + mxidx) % mxidx;
        if(cmd == '+') arr[pt] = (arr[pt] + 1) % mxNum;
        if(cmd == '-') arr[pt] = (arr[pt] - 1 + mxNum) % mxNum;
        if(cmd == '.') cout << (char)arr[pt];
        if(cmd == ']' && arr[pt] != 0) idx = pairidx[idx]-1;
        if(cmd == '[' && arr[pt] == 0) idx = pairidx[idx]-1;
        idx++;
    }
    cout << ans << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    cin.ignore();
    rep(i, 1, tc+1){
        cout << "PROGRAM #" << i << ":\n";
        solve();
    }
    return 0;
}

