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

int N;
string words[20];
priority_queue<string, vector<string>, greater<string>> PQ;
string ans = "";

void solve(){
    cin >> N;
    rep(i, 0, N){
        string S; cin >> S;
        S += (char)(255);
        PQ.push(S);
    }
    while(!PQ.empty()){
        string S = PQ.top(); PQ.pop();
        if(S[0] == (char)(255)) continue;
        ans += S[0];
        if(S.size() > 1) PQ.push(S.substr(1));
    }
    cout << ans;
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