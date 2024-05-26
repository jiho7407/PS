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

string S;
string T = "welcome to code jam";

int btr(int sidx, int tidx){
    if(tidx == T.size()) return 1;
    if(sidx == S.size()) return 0;
    int ret = 0;
    if(S[sidx] == T[tidx]) ret += btr(sidx+1, tidx+1);
    ret += btr(sidx+1, tidx);
    return ret;
}

void solve(){
    getline(cin, S);
    int ans = btr(0, 0)%10000;
    cout << setfill('0') << setw(4) << ans << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    cin.ignore();
    rep(i, 1, tc+1){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}