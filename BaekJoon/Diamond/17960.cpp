#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, Q;
const int mod = 1e9+1;
vector<int> xv, yv, zv;

void solve(){
    cin >> N >> Q;
    rep(i, 0, N){
        int x, y, z;
        cin >> x >> y >> z;
        xv.push_back(x);
        yv.push_back(y);
        zv.push_back(z);
    }
    ll S = 0;
    while(Q--){
        ll lx, ly, lz, rx, ry, rz;
        cin >> lx >> ly >> lz >> rx >> ry >> rz;
        lx = (lx^S)%mod;
        ly = (ly^S)%mod;
        lz = (lz^S)%mod;
        rx = (rx^S)%mod;
        ry = (ry^S)%mod;
        rz = (rz^S)%mod;
        if(lx > rx) swap(lx, rx);
        if(ly > ry) swap(ly, ry);
        if(lz > rz) swap(lz, rz);
        ll cnt = 0;
        rep(i, 0, N){
            cnt += (((int)lx <= xv[i]) & (xv[i] <= (int)rx) & ((int)ly <= yv[i]) & (yv[i] <= (int)ry) & ((int)lz <= zv[i]) & (zv[i] <= (int)rz));
        }
        cout << cnt << '\n';
        S+= cnt;
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}