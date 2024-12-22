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

int calc_size(int X){
    int ln = 1, po = 1, ret = 0;
    while(po*10 <= X){
        ret += ln*po*9;
        ln++;
        po *= 10;
    }
    ret += (X-po+1)*ln;
    return ret;
}

void solve(){
    int N; cin >> N;
    int ok = 0, ng = 20000000;
    while(ng - ok > 1){
        int mid = (ok + ng)>>1;
        if(calc_size(mid) < N) ok = mid;
        else ng = mid;
    }
    vector<int> ret;
    int M = ok+1;
    while(M){
        ret.push_back(M%10);
        M /= 10;
    }
    reverse(ret.begin(), ret.end());
    cout << ret[N-calc_size(ok)-1];
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