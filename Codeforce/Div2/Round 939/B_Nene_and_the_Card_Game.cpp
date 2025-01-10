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
    int N; cin >> N;
    vector<int> cnts(N);
    rep(i, 0, N) cnts[i] = 0;
    rep(i, 0, N){
        int x; cin >> x; x--;
        cnts[x]++;
    }
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    rep(i, 0, N){
        if(cnts[i] == 0) cnt0++;
        else if(cnts[i] == 1) cnt1++;
        else cnt2++;
    }
    if(cnt2 > (N - cnt2 - cnt1)){
        cout << cnt2 + cnt1 << '\n';
    }
    else cout << cnt2 << '\n';
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