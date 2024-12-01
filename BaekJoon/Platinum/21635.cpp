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
vector<ll> A, B;

void solve(){ 
    cin >> N;
    A.resize(N); B.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    ll Asum = 0, Bsum = 0;
    rep(i, 0, N){
        Asum += A[i];
        Bsum += B[i];
    }

    int cnt = 0;
    rep(i, 0, N){
        if(B[i] <= Asum-A[i]) cnt++;
    }

    rep(i, 0, N){
        if(cnt - (B[i] <= Asum-A[i]) == N-1 && Bsum - B[i] <= Asum){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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