#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

bool cmp(pll a, pll b){
    return abs(a.first - a.second) > abs(b.first - b.second);
}

void solve(){
    int N, K; cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    vector<pll> C(N);
    rep(i, 0, N) C[i] = {A[i], B[i]};
    sort(C.begin(), C.end(), cmp);
    ll ans = 0;
    int a = 0, b = 0;
    int mx = (N+K)/2;
    rep(i, 0, N){
        if(a == mx) ans += C[i].second;
        else if(b == mx) ans += C[i].first;
        else{
            if(C[i].first > C[i].second){
                ans += C[i].first;
                a++;
            }
            else{
                ans += C[i].second;
                b++;
            }
        }
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