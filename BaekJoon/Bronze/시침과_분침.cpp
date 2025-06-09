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

bool ans[360];

void solve(){
    rep(i, 0, 1440){
        int h = i/60;
        int m = i%60;
        if(m%2) continue;
        int hang = h*30 + m/2;
        int mang = m*5;
        cout << hang << ' ' << mang << '\n';
        int ang = abs(hang-mang);
        ans[ang] = 1;
        ans[360-ang] = 1;
    }
    int N;
    while(cin >> N){
        cout << (ans[N] ? "Y\n" : "N\n");
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