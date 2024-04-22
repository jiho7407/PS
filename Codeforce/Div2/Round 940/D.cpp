#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;

void solve(){
    cin >> N;
    vector<ll> A(N+1), XOR(N+1);
    rep(i, 1, N+1){
        cin >> A[i];
        XOR[i] = XOR[i-1] ^ A[i];
    }
    vector<ll> ones[31];
    rep(i, 0, N+1){
        rep(j, 0, 31){
            if((XOR[i] >> j) & 1) ones[j].push_back(i);
        }
    }
    ll ans = 0;
    rep(i, 1, N+1){
        int b = 31 - __builtin_clz(A[i]);
        int l = lower_bound(ones[b].begin(), ones[b].end(), i) - ones[b].begin();
        int r = ones[b].size() - l;
        ans += 1ll * l * r;
        ans += 1ll * (i-l) * (N-(i-1)-r);
    }
    cout << ans << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}