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

ll N, K, L;
vector<ll> A;

bool chk(ll mid){
    ll cur = 0;
    // cout << "mid: " << mid << '\n';
    rep(i, 0, N){
        // cout << cur << ' ';
        if(cur < A[i] - mid) return false;
        if(cur < A[i]){
            ll tm = A[i] - cur;
            cur = cur + K + (mid - tm);
        }
        else{
            cur = max(cur, A[i] + mid) + K;
        }

        if(cur >= L) return true;
    }
    // cout << cur << '\n';
    if(cur >= L) return true;
    return false;
}

void solve(){
    cin >> N >> K >> L;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];
    K *= 2; L *= 2;
    rep(i, 0, N) A[i] *= 2;
    ll ok = 2e9, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok+ng)/2;
        if(chk(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
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