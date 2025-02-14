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
    string S; cin >> S;
    int ans = 0;
    int idx = 0;
    while(idx < S.size()){
        if(idx+1 < S.size() && S[idx] == '0' && S[idx+1] == '0'){
            ans++;
            idx += 2;
        }
        else{
            ans++;
            idx++;
        }
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