#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int op[4];
map<char, int> opmp;
string S;
vector<string> calc;

bool isnum(char c){
    return '0'<=c && c<='9';
}

void solve(){
    rep(i, 0, 4) cin >> op[i];
    opmp['+'] = op[0];
    opmp['-'] = op[1];
    opmp['*'] = op[2];
    opmp['/'] = op[3];

    cin >> S;
    for(int i = 0, j = 0; i<S.size(); i=j+1, j = i){
        while(j<S.size() && isnum(S[j])) j++;
        calc.push_back(to_string(stoll(S.substr(i, j-i))));
        calc.push_back(S.substr(j, 1));
    }

    for(int opidx = 4; opidx >= 1; opidx--){
        stack<string> stk;
        while(!calc.empty()){
            string cur = calc.back();
            calc.pop_back();
            if(isnum(cur[0]) || opmp[cur[0]] != opidx){
                stk.push(cur);
                continue;
            }
            ll a = stoll(stk.top());
            stk.pop();
            ll b = stoll(calc.back());
            calc.pop_back();

            if(cur[0] == '+') stk.push(to_string(a+b));
            else if(cur[0] == '-') stk.push(to_string(a-b));
            else if(cur[0] == '*') stk.push(to_string(a*b));
            else if(cur[0] == '/') stk.push(to_string(a/b));
        }
        while(!stk.empty()){
            calc.push_back(stk.top());
            stk.pop();
        }
    }
    cout << stoll(calc[0]);
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}