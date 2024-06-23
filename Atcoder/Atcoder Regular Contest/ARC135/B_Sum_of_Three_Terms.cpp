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

void solve(){
    int N; cin >> N;
    vector<ll> S(N);
    rep(i, 0, N) cin >> S[i];
    if(N == 1){
        cout << "Yes\n";
        cout << "0 0 " << S[0] << "\n";
        return;
    }
    if(N == 2){
        cout << "Yes\n";
        cout << S[0] << " 0 0 " << S[1] << "\n";
        return;
    }
    vector<ll> A(N+2);
    A[0] = A[1] = 0;
    rep(i, 0, N) A[i+2] = S[i] - A[i] - A[i+1];
    ll amin = -1e18, bmin = -1e18, abmax = 1e18;
    rep(i, 0, N+2){
        if(i%3 == 0) amin = max(amin, -A[i]);
        else if(i%3 == 1) bmin = max(bmin, -A[i]);
        else abmax = min(abmax, A[i]);
    }
    if(amin + bmin > abmax){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    rep(i, 0, N+2){
        if(i%3 == 0) cout << A[i] + amin << " ";
        else if(i%3 == 1) cout << A[i] + bmin << " ";
        else cout << A[i] - amin - bmin << " ";
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}