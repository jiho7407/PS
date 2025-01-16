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
    int N; cin >> N;
    int ans = 0;
    while(N--){
        int v[3]; cin >> v[0] >> v[1] >> v[2];
        if(v[0] == -1) continue;
        if(v[1] == -1 && v[2] != -1) continue;
        
        if(v[1] == -1) ans++;
        else if(v[2] == -1 && v[0] <= v[1]) ans++;
        else if(v[0] <= v[1] && v[1] <= v[2]) ans++;
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