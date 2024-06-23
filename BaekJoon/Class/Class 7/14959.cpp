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

// const int mxN = 1'000'000;
int N;
vector<int> A, pi;

void solve(){
    cin >> N;
    A.resize(N); pi.resize(N);
    rep(i, 0, N) cin >> A[i];
    reverse(A.begin(), A.end());
    rep(i, 1, N){
        int j = pi[i-1];
        while(j > 0 && A[i] != A[j]) j = pi[j-1];
        if(A[i] == A[j]) j++;
        pi[i] = j;
    }
    int mx = 1e9, k, p;
    rep(idx, 0, N){
        // if(pi[idx] == 0) continue;
        int tk = N-idx-1, tp = idx-pi[idx]+1;
        // cout << idx << ' ' << tk << ' ' << tp << '\n';
        if(tk+tp < mx || (tk+tp == mx && tp<p)){
            mx = tk+tp;
            k = tk;
            p = tp;
        }
    }
    cout << k << ' ' << p << '\n';
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