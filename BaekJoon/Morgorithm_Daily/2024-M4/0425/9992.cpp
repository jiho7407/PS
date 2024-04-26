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

int calc(string s){
    if(DP.find(s) != DP.end()) return DP[s];
    if(s.size() <= 2) return 1;
    int ret = 1, N = s.size();
    rep(i, 1, (N+1)/2){
        // S+T -> S + (S + T)
        if(s.substr(0, i) == s.substr(i, i)) ret += calc(s.substr(i, N-i));
        // S+T -> T + (S + T)
        if(s.substr(0, i) == s.substr(N-i, i)) ret += calc(s.substr(i, N-i));
        // S+T -> (S + T) + S
        if(s.substr(0, i) == s.substr(N-i, i)) ret += calc(s.substr(0, N-i));
        // S+T -> (S+T)+T
        if(s.substr(N-2*i, i) == s.substr(N-i, i)) ret += calc(s.substr(0, N-i));
    }
    return DP[s] = ret % mod;
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