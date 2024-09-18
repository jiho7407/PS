#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    string S;
    cin >> S;
    stack<char> stk;
    for(auto c: S){
        if(!stk.empty() && c == ')'){
            string tmp = "";
            while(stk.top() != '('){
                tmp += stk.top();
                stk.pop();
            }
            stk.pop();
            reverse(tmp.begin(), tmp.end());
            int cnt = stk.top() - '0'; stk.pop();
            rep(i, 0, cnt) for(auto x: tmp) stk.push(x);
        }
        else stk.push(c);
    }
    cout << stk.size() << '\n';
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