#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define ull unsigned long long


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<ull> A, B;

bool check(ull x){
    ull val = x;
    rep(i, 0, N){
        ull l = A[i], r = B[i];
        if(l <= x && x <= r){
            val = val^(((x|l)+(x&r)*(l^r)));
        }
    }
    return (val >= 0x0123456789ABCDEF);
}

void solve(){
    cin >> N;
    A.resize(N); B.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];

    ull ok = 1000000000000000001ULL, ng = 0;
    while(ok - ng > 1){
        ull mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ng << '\n';
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