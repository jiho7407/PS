#include <bits/stdc++.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, ans, idx;
string S;

void solve(){
    cin >> N >> S;
    ans = 0;
    idx = -1;
    rep(i, 0, N){
        if(S[i] == 'B') continue;
        if(idx == -1) idx = i;
        else{
            if(i-idx == 1) ans += 2;
            else if(i-idx == 2) ans += 1;
            idx = i;
        }
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}