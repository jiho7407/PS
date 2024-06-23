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

int N;
string ans[800];

void makeans(int idx, int N, bool ismid){
    // cout << idx << ' ' << N << ' ' << ismid << endl;
    int block = 1; rep(i, 0, N-1) block *= 3;
    if(N == 0){
        if(ismid) ans[idx] += ".";
        else ans[idx] += "#";
        return;
    }
    if(ismid){
        block *= 3;
        rep(i, 0, block) rep(j, 0, block) ans[idx+i] += ".";
        return;
    }
    rep(i, 0, 3) makeans(idx, N-1, false);
    makeans(idx+block, N-1, false);
    makeans(idx+block, N-1, true);
    makeans(idx+block, N-1, false);
    rep(i, 0, 3) makeans(idx+block*2, N-1, false);
    return;
}

void solve(){
    cin >> N;
    makeans(0, N, false);
    rep(i, 0, (int)pow(3, N)) cout << ans[i] << '\n';
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
