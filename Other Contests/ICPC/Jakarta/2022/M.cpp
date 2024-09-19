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

int N, Q;
ll A[200000], B[200000];
ll pfsum[200001], sfsum[200001];

void solve(){
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) pfsum[i+1] = pfsum[i] + A[i];
    for(int i = N-1; i >= 0; i--) sfsum[i] = sfsum[i+1] + B[i];
    bool flag = false;
    rep(i, 0, N) if(A[i] + B[i] < 0) flag = true;
    if(pfsum[N] < 0 || sfsum[0] < 0) flag = true;

    // rep(i, 0, N+1) cout << pfsum[i] << ' ';
    // cout << '\n';
    // rep(i, 0, N+1) cout << sfsum[i] << ' ';
    // cout << '\n';
    while(Q--){
        int L, R; cin >> L >> R;
        L--; R--;
        if(flag){
            cout << "flawed\n";
            continue;
        }
        if(L == R) cout << 0 << '\n';
        else if(L < R) cout << min(pfsum[R] - pfsum[L], (sfsum[0] - sfsum[L]) + (sfsum[R] - sfsum[N])) << '\n';
        else cout << min(sfsum[R] - sfsum[L], (pfsum[R] - pfsum[0]) + (pfsum[N] - pfsum[L])) << '\n';
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