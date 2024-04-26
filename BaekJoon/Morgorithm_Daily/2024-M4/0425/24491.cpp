#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M;

void solve(){
    cin >> N >> M;
    int ans = 0;
    ll Mbit = 1 << (63 - __builtin_clzll(M));
    while(N > Mbit){
        if(N%2) N++;
        else N /= 2;
        ans++;
    }
    ans += M - N;
    cout << N << " " << M << " " << Mbit << " " << ans << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}