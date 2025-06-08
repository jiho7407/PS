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

int N, K;
ll A[5000], B[5000];
ll Apf[5001], Bpf[5001], Asf[5001], Bsf[5001];
ll Amn[5001], Bmn[5001];

void solve(){
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];

    ll Asum = 0, Bsum = 0;
    rep(i, 0, N) Asum += A[i], Bsum += B[i];
    rep(i, 0, N){
        Apf[i+1] = Apf[i] + A[i];
        Bpf[i+1] = Bpf[i] + B[i];
    }
    for(int i = N-1; i >= 0; i--){
        Asf[i] = Asf[i+1] + A[i];
        Bsf[i] = Bsf[i+1] + B[i];
    }

    rep(i, 0, N+1) Amn[i] = Bmn[i] = 1e18;
    Amn[0] = Asum;
    Bmn[0] = Bsum;
    rep(i, 1, N+1){
        rep(j, 0, i+1){
            Amn[i] = min(Amn[i], Asum - (Apf[j] + Asf[N-(i-j)]));
            Bmn[i] = min(Bmn[i], Bsum - (Bpf[j] + Bsf[N-(i-j)]));
        }
    }

    ll ans = 1e18;
    rep(i, 0, K+1){
        ans = min(ans, max(Amn[i], Bmn[K-i]));
    }
    cout << ans << '\n';
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