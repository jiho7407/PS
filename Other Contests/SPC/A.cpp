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
    int sx, sy, ex, ey, px, py;
    cin >> sx >> sy >> ex >> ey >> px >> py;
    
    if(sx == ex){
        if(px == sx && min(sy, ey) <= py && py <= max(sy, ey)) cout << 2;
        else cout << 0;
    }
    else if(sy == ey){
        if(py == sy && min(sx, ex) <= px && px <= max(sx, ex)) cout << 2;
        else cout << 0;
    }
    else{
        cout << 1;
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