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

void print(int border){
    if(N <= border/2){
        rep(i, 0, N-1) cout << "A";
        cout << "B";
        cout << "\n";
        return;
    }
    rep(i, 0, N){
        if(i%border < border/2) cout << "A";
        else cout << "B";
    }
    cout << "\n";
}

void solve(){
    cin >> N;

    print(128);
    print(64);
    print(32);
    print(16);
    print(8);
    print(4);
    print(2);
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