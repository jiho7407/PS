#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int R, C, K;

void solve(){
    cin >> R >> C >> K;
    bool flag = true;
    while(R--){
        string M, P;
        cin >> M >> P;
        bool broken = false;
        rep(i, 0, C) if(M[i] == '-') broken = true;
        bool turnOn = false;
        rep(i, 0, K) if(P[i] == '*') turnOn = true;
        if(broken && turnOn) flag = false;
    }
    cout << (flag ? "Y" : "N");
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