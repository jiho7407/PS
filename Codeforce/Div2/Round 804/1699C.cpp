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
vector<int> A;
map<int, int> mp;
ll mod = 1e9+7;

void solve(){
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) mp[A[i]] = i;

    if(mp[0] < mp[1]){
        reverse(A.begin(), A.end());
        rep(i, 0, N) mp[A[i]] = i;
    }

    ll ans = 1;
    int L = mp[0], R = mp[0];
    rep(i, 1, N){
        int idx = mp[i];
        if(idx < L){
            L = idx;
            continue;
        }
        if(idx > R){
            R = idx;
            continue;
        }
        ans *= ((R-L+1) - i);
        ans %= mod;
    }
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