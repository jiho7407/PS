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
pii arr[100000];

void solve(){
    cin >> N;
    rep(i, 0, N){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr+N);
    int ans = 0;
    rep(i, 0, N) ans = max(ans, arr[i].second - i);
    cout << ans+1 << '\n';
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