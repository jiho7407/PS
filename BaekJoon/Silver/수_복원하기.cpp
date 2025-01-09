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
    ll N; cin >> N;
    vector<pii> divs;
    for(ll i = 2; i*i <= N; i++){
        if(N%i == 0){
            int cnt = 0;
            while(N%i == 0){
                N /= i;
                cnt++;
            }
            divs.push_back({i, cnt});
        }
    }
    if(N > 1) divs.push_back({N, 1});
    for(auto [a, b]:divs){
        cout << a << ' ' << b << '\n';
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