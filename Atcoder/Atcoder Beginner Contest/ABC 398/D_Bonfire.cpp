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
    int N, R, C; cin >> N >> R >> C;
    string S; cin >> S;

    int cx = 0, cy = 0;
    set<pii> smoke;
    smoke.insert({0, 0});
    for(auto c: S){
        if(c == 'N') cx--;
        else if(c == 'S') cx++;
        else if(c == 'W') cy--;
        else cy++;
        smoke.insert({-cx, -cy});
        if(smoke.find({R-cx, C-cy}) != smoke.end()) cout << 1;
        else cout << 0;
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