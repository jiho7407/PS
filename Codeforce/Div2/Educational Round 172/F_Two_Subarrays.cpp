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
    vector<int> a(N), b(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];

    int Q; cin >> Q;
    while(Q--){
        int op, L, R; cin >> op >> L >> R;
        if(op == 1) a[L-1] = R;
        else if(op == 2) b[L-1] = R;
        else{
            L--; R--;
            int ans = -1e9;
            rep(i, L, R+1) rep(j, i, R+1) rep(k, j+1, R+1) rep(l, k, R+1){
                int sum = 0;
                rep(m, i, j+1) sum += a[m];
                rep(m, k, l+1) sum += a[m];
                sum += b[i] + b[j] + b[k] + b[l];
                ans = max(ans, sum);
            }
            cout << ans << endl;
        }
    }
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