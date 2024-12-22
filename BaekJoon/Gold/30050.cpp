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
    ll Q; cin >> Q;
    unordered_map<ll, ll> mp;
    while(Q--){
        ll op, a, b; cin >> op >> a >> b;
        if(op == 1){
            mp[b] = a;
        }
        else{
            ll ret = 0;
            while(a != b){
                if(a > b) swap(a, b);
                ret += b;
                if(mp.find(b) == mp.end()) b >>= 1;
                else b = mp[b];
            }
            ret += a;
            cout << ret << '\n';
        }
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