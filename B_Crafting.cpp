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
    vector<int> A(N), B(N), C(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) C[i] = A[i]-B[i];
    sort(C.begin(), C.end());

    if(C[0] >= 0){
        cout << "YES\n";
        return;
    }

    if(C[1] < 0){
        cout << "NO\n";
        return;
    }

    if(C[0] + C[1] >= 0){
        cout << "YES\n";
        return;
    }
    else{
        cout << "NO\n";
        return;
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