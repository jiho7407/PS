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
int arr[100];
int cnt[101];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> arr[i];
    fill(cnt, cnt+101, 0);
    rep(i, 0, N) cnt[arr[i]]++;
    int mx = 0;
    rep(i, 0, 101) mx = max(mx, cnt[i]);
    cout << N - mx << '\n';
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