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

string S, T;

void solve(){
    cin >> S >> T;
    vector<char> stk;
    for(auto c : S){
        stk.push_back(c);
        while(stk.size() >= T.size()){
            string tmp = "";
            for(int i = 0; i < T.size(); i++){
                tmp += stk[stk.size()-T.size()+i];
            }
            if(tmp == T){
                for(int i = 0; i < T.size(); i++){
                    stk.pop_back();
                }
            } else {
                break;
            }
        }
    }
    for(auto c : stk){
        cout << c;
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}