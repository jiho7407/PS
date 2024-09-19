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
map<string, ld> mp;

bool islow(char S){
    int idx = S-'a';
    return 0 <= idx && idx <= 25;
}

bool iscap(char S){
    int idx = S-'A';
    return 0 <= idx && idx <= 25;
}

bool isnum(char S){
    int idx = S-'0';
    return 0 <= idx && idx <= 9;
}

void solve(){
    cin >> N;
    while(N--){
        string s; ld p;
        cin >> s >> p;
        mp[s] = p;
    }

    string S; cin >> S;
    cout << fixed << setprecision(10);

    ld ans = 0;
    for(int i = 0, j = 0; i < S.size(); i = j+1, j = i){
        string atom, num;
        while(j < S.size() && islow(S[j+1])) j++;
        atom = S.substr(i, j-i+1);
        i = j+1;
        while(j < S.size() && isnum(S[j+1])) j++;
        num = S.substr(i, j-i+1);
        if(num.empty()) num = "1";
        ans += mp[atom] * stold(num);
    }
    cout << ans << '\n';
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