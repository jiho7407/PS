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

const int mod = 2014;
string S;
map<string, int> DP;

int check(string s, string t){
    if(s.size() == t.size()) return 0;
    if(s.size() < t.size()) swap(s, t);
    int ret = 0;
    if(s.substr(0, t.size()) == t) ret++;
    if(s.substr(s.size()-t.size(), t.size()) == t) ret++;
    return ret;
}

int calc(string s){
    if(DP.find() != DP.end()) return DP[s];
    int ret = 1, N = s.size();
    rep(i, 1, N){
        ret += check(s.substr(0, i), s.substr(i, N-i));
    }
}

void solve(){
    cin >> S;
    cout << calc(S) - 1;
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