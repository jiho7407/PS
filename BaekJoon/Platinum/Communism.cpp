#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimization("unroll-loops")

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
    vector<ll> A, B;
    rep(i, 0, N/2){
        ll x; cin >> x;
        A.push_back(x);
    }
    rep(i, N/2, N){
        ll x; cin >> x;
        B.push_back(x);
    }
    ll D; cin >> D;
    vector<ll> v1, v2;
    v1.push_back(0);
    v2.push_back(0);
    
    int sz, idx1, idx2, idx3, idx;
    ll ret1, ret2, ret3;
    for(auto x: A){
        sz = v1.size();
        vector<ll> nxt(3*sz);
        idx1 = 0, idx2 = 0, idx3 = 0, idx = 0;
        while(idx1 < sz || idx2 < sz || idx3 < sz){
            ret1 = idx1 < sz ? v1[idx1]+x : 5e18;
            ret2 = idx2 < sz ? v1[idx2]-x : 5e18;
            ret3 = idx3 < sz ? v1[idx3] : 5e18;
            ll mn = min({ret1, ret2, ret3});
            nxt[idx++] = mn;
            if(ret1 == mn) idx1++;
            else if(ret2 == mn) idx2++;
            else if(ret3 == mn) idx3++;
        }
        swap(v1, nxt);
    }

    for(auto x: B){
        sz = v2.size();
        vector<ll> nxt(3*sz);
        idx1 = 0, idx2 = 0, idx3 = 0, idx = 0;
        while(idx1 < sz || idx2 < sz || idx3 < sz){
            ret1 = idx1 < sz ? v2[idx1]+x : 5e18;
            ret2 = idx2 < sz ? v2[idx2]-x : 5e18;
            ret3 = idx3 < sz ? v2[idx3] : 5e18;
            ll mn = min({ret1, ret2, ret3});
            nxt[idx++] = mn;
            if(ret1 == mn) idx1++;
            else if(ret2 == mn) idx2++;
            else if(ret3 == mn) idx3++;
        }
        swap(v2, nxt);
    }
    v2.push_back(5e18);

    ll ans = 0;
    int L = 0, R = 0;
    for(auto x1: v1){
        while(L < v2.size() && v2[L] < x1-D) L++;
        while(R < v2.size()-1 && v2[R+1] <= x1+D) R++;
        ans += R-L+1;
    }
    cout << ans << '\n';
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