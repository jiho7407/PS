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

int N, M;
int A[100][100];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M){
        cin >> A[i][j];
    }
    rep(i, 0, N) rep(j, 0, M){
        int B; cin >> B;
        A[i][j] += B;
    }
    rep(i, 0, N){
        rep(j, 0, M){
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
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