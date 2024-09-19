#include <bits/stdc++.h>
#define ll long long
#define rep(i, L, R) for(int i = L; i<R; i++)

using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
}

int N;
ll A[3000];
ll DP[500][500];
int K[500][500];

ll game(int L, int R){
    if(L > R) return 0;
    if(L == R) return DP[L][R] = A[L];

    ll &ret = DP[L][R];
    if(ret != -1) return ret;

    ret = 0;
    rep(i, L, R+1){
        ll tmp = A[i] + min(game(L, i-1), game(i+1, R));
        if(ret < tmp){
            ret = tmp;
            K[L][R] = i;
        }
    }
    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    if(N > 500){
        cout << 0 << '\n';
        return;
    }

    fill_n(&DP[0][0], 500*500, -1);
    cout << game(0, N-1) << '\n';
    
    rep(i, 0, N){
        rep(j, 0, N) cout << K[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    fastio();
    int tc;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
}