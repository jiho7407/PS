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

vector<int> v;
map<pii, int> mp;

int calc(int L, int R){
    if(mp.find({L, R}) != mp.end()) return mp[{L, R}];
    if(L == R){
        int Lidx = upper_bound(v.begin(), v.end(), L) - v.begin() - 1;
        if(v[Lidx] == L) return Lidx;
        else return calc(L-v[Lidx], R-v[Lidx]) + Lidx;
    }
    int ret = 0;
    auto Lidx = upper_bound(v.begin(), v.end(), L) - v.begin() - 1;
    auto Ridx = upper_bound(v.begin(), v.end(), R) - v.begin() - 1;
    if(Lidx == Ridx) ret = calc(L - v[Lidx], R - v[Ridx]) + Lidx;
    else{
        ret = max(ret, calc(L, v[Ridx]-1));
        ret = max(ret, calc(v[Ridx], R));
    }
    return mp[{L, R}] = ret;
}


void solve(){
    v.push_back(0);
    v.push_back(1);
    while(v.back() < 1e9){
        v.push_back(v.back()*2+1);
    }
    int TC; cin >> TC;
    while(TC--){
        int L, R; cin >> L >> R;
        cout << calc(L, R) << '\n';
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