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

int N;
int T[100000];
ll A[100000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> T[i];
    A[0] = 1LL << T[0];
    rep(i, 1, N){
        ll base = 1LL << T[i];
        ll add = A[i-1]/base;
        if(add%2) add++;
        A[i] = base * (add + 1);
    }
    cout << A[N-1] << '\n';
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