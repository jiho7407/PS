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
    ll N;
    while(1){
        cin >> N;
        if(cin.eof()) break;
        vector<bool> v(10);
        rep(i,0,10) v[i] = 0;
        ll tmp = 1;
        while(1){
            ll n = N*tmp;
            while(n){
                v[n%10] = 1;
                n/=10;
            }
            bool flag = 1;
            rep(i,0,10) if(!v[i]) flag = 0;
            if(flag){
                cout << tmp << '\n';
                break;
            }
            tmp++;
        }
    }
}

int main(){
    // fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}