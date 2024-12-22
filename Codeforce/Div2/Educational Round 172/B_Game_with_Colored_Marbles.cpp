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
    vector<int> cnts(1001);
    int N; cin >> N;
    rep(i, 0, N){
        int x; cin >> x;
        cnts[x]++;
    }
    int ocnt = 0, mo = 0;
    rep(i, 1, N+1){
        if(cnts[i] == 1) ocnt++;
        else if(cnts[i] > 1) mo++;
    }

    cout << ((ocnt+1)/2*2) + mo << '\n';
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