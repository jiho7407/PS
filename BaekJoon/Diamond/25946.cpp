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


ll sm(ll L, ll R){
    return (L+R)*(R-L+1)/2;
}

bool inter(ll cI, ll cpos, ll clen, ll M, ll pos){
    pll rng = {cpos, cpos+clen};
    rng.first += sm(cI+1, M-1);
    rng.second += (M-cI);
    cout << rng.first << ' ' << rng.second << ' ' << pos << '\n';
    pll rng2 = {M*(M-1)/2+1, M*(M+1)/2};
    if(rng.first <= rng2.first && rng2.first <= rng.second) return 1;
}

int N;
vector<ll> v;

void solve(){
    cin >> N;
    v.resize(N);
    rep(i, 0, N) cin >> v[i];
    sort(v.begin(), v.end());

    ll cI = 0, cpos = 0, clen = 0;
    ll ok = v.back(), ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(get_rng(mid).second-v[0] < 0) ng = mid;
        else ok = mid;
    }
    if(ok%2 == 0) ok++;
    pll ret = get_rng(ok);
    cI = ok; cpos = ret.first; clen = ret.second - v[0];
    cout << cI << ' ' << cpos << ' ' << clen << '\n';

    rep(i, 1, N){
        // 겹치거나 오른쪽에있는 범위 찾기
        ll ok = v.back(), ng = -1;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            if(inter(cI, cpos, clen, mid, v[i])) ok = mid;
            else ng = mid;
        }
        if(ok%2 == 0) ok++;
        
        // 해당 범위로 업데이트
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