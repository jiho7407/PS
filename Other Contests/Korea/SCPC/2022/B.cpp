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

int N;
ll A[3000], DP[3000][3000], Left[3000][3000], Right[3000][3000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    fill_n(&DP[0][0], 3000*3000, 0);

    rep(i, 0, N) DP[i][i] = Left[i][i] = Right[i][i] = A[i];
    rep(d, 1, N) rep(i, 0, N-d){
        int j = i+d;
        int ok = i, ng = j+1;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            if(Left[i][mid-1] < Right[mid][j]) ok = mid;
            else ng = mid;
        }
        
        cout << i << ' ' << j << ' ' << ok << '\n';
        Left[i][j] = max(Left[i][ok-1], DP[i][ok-1] + A[ok]);
        Right[i][j] = max(Right[ok+1][j], DP[ok+1][j] + A[ok]);
        DP[i][j] = max(Left[i][ok], Right[ok+1][j]);
    }
    cout << DP[0][N-1] << '\n';

    rep(i, 0, N){
        rep(j, 0, N) cout << DP[i][j] << ' ';
        cout << '\n';
    }
}

ll game(int L, int R){
    if(L > R) return 0;
    if(L == R) return DP[L][R] = A[L];

    ll &ret = DP[L][R];
    if(ret != -1) return ret;

    ret = 0;
    rep(i, L, R+1){
        ret = max(ret, A[i] + min(game(L, i-1), game(i+1, R)));
    }
    return ret;
}

void naive(){
    fill_n(&DP[0][0], 500*500, -1);
    cout << game(0, N-1) << '\n';

    rep(i, 0, N){
        rep(j, 0, N) cout << DP[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
        // naive();
    }
    return 0;
}