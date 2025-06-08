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

ll N;
ll A[10000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    vector<ll> V1, V2;
    ll zcnt = 0;
    rep(i, 0, N){
        if(A[i] == 0) zcnt++;
        if(A[i] > 0) V1.push_back(A[i]);
        else V2.push_back(A[i]);
    }
    ll n1 = V1.size(), n2 = V2.size();
    map<ll, ll> mp1, mp2;
    rep(i, 0, n1) rep(j, i+1, n1) mp1[V1[i]+V1[j]]++;
    rep(i, 0, n2) rep(j, i+1, n2) mp2[V2[i]+V2[j]]++;

    ll ans = 0;
    for(auto x: V1) if(mp2.count(-x)) ans += mp2[-x];
    for(auto x: V2) if(mp1.count(-x)) ans += mp1[-x];
    ans += zcnt*(zcnt-1)*(zcnt-2)/6;
    cout << ans;
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