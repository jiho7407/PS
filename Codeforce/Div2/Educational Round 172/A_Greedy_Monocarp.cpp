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

bool cmp(ll a, ll b){
    return a > b;
}

void solve(){
    ll N, K;
    cin >> N >> K;
    vector<ll> v;
    rep(i, 0, N){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = K;
    rep(i, 0, N){
        if(v[i] <= ans) ans -= v[i];
        else break;
    }
    cout << ans << "\n";
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