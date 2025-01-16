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

void solve(){
    vector<string> v;
    v.push_back("northlondo");
    v.push_back("branksomeh");
    v.push_back("koreainter");
    v.push_back("stjohnsbur");

    string S; cin >> S;
    rep(i, 0, 26){
        if(S == v[0]) cout << "NLCS";
        if(S == v[1]) cout << "BHA";
        if(S == v[2]) cout << "KIS";
        if(S == v[3]) cout << "SJA";
        string T = "";
        rep(j, 0, 10){
            T += (char)((S[j]-'a'+1)%26+'a');
        }
        S = T;
    }
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