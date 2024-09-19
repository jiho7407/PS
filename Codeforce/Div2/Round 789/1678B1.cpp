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

int N;
string S;

void solve(){
    cin >> N >> S;
    vector<int> cnt;
    cnt.push_back(1);
    rep(i, 1, N){
        if(S[i] == S[i-1]) cnt.back()++;
        else cnt.push_back(1);
    }
    
    vector<int> oddidx;
    rep(i, 0, cnt.size()) if(cnt[i] % 2) oddidx.push_back(i);

    int ans = 0;
    for(int i = 0; i<oddidx.size(); i += 2) ans += oddidx[i+1] - oddidx[i];
    cout << ans << '\n';
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