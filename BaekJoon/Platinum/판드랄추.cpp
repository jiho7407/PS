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
    int p, q; cin >> p >> q;
    if(abs(p-q)%2){
        cout << -1 << '\n';
        return;
    }
    bool flag = p < q;
    string S = "AB";
    if(flag) swap(p, q);
    int x = (p-q)/2;
    if((p^x) == (q+x)) cout << 1 << '\n';
    else cout << 2 << '\n';
    while(p != q){
        cout << S[flag] << ' ' << x << '\n';
        p ^= x;
        q += x;
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