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
int A[100][100], cur[100][100];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];
    fill_n(&cur[0][0], 100*100, 101);
    rep(k, 1, 101){
        rep(i, 0, N){
            int cnt = 0;
            rep(j, 0, M){
                if(cur[i][j] < A[i][j]){ cout << "NO\n"; return; }
                if(cur[i][j] != 101 || A[i][j] == k) cnt++;
            }
            if(cnt == M){
                rep(j, 0, M) cur[i][j] = min(cur[i][j], A[i][j]);
            }
        }
        rep(j, 0, M){
            int cnt = 0;
            rep(i, 0, N){
                if(cur[i][j] < A[i][j]){ cout << "NO\n"; return; }
                if(cur[i][j] != 101 || A[i][j] == k) cnt++;
            }
            if(cnt == N){
                rep(i, 0, N) cur[i][j] = min(cur[i][j], A[i][j]);
            }
        }
    }
    rep(i, 0, N) rep(j, 0, M) if(cur[i][j] != A[i][j]){ cout << "NO\n"; return; }
    cout << "YES\n";
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << ": ";
        solve();
    }
    return 0;
}