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
    int N, M; cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M){
        if(i%4 == 0 || i%4 == 3){
            if(j%4 == 0 || j%4 == 3) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        else{
            if(j%4 == 0 || j%4 == 3) cout << 0 << ' ';
            else cout << 1 << ' ';
        }
        if(j == M-1) cout << '\n';
    }
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}