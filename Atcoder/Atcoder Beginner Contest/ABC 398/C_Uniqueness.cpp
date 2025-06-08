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
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    map<int, int> mp;
    rep(i, 0, N) mp[A[i]]++;
    int ans = -1, mx = -1;
    rep(i, 0, N) if(mp[A[i]] == 1){
        if(A[i] > mx){
            mx = A[i];
            ans = i+1;
        }
    }
    cout << ans;
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