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

ll XOR(ll N){
    if(N%4 == 0) return N;
    else if(N%4 == 1) return 1;
    else if(N%4 == 2) return N + 1;
    else return 0;
}

void solve(){
    ll L, R; cin >> L >> R;
    cout << (XOR(R) ^ XOR(L-1)) << "\n";
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