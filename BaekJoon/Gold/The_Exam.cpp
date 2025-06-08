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
    int N, K; cin >> N >> K;
    if(K > N/2) cout << "NIE";
    else if(N%2){
        cout << 1 << ' ';
        for(int i = (N+2)/2, j = N; i > 1; i--, j--) cout << i << ' ' << j << ' ';
    }
    else{
        for(int i = N/2, j = N; i > 0; i--, j--) cout << i << ' ' << j << ' ';
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