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
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    for(int i = 0, j = 0, d = 0; i<N; i++){
        while(j < N && A[i]*2 > A[j]) j++; // i번째 떡은 j번째 이상의 떡에 매칭되어야함
        d = max(d, j-i); // 그 차이의 최댓값을 구하자.
        if(i >= N/2 || i+d >= N){
            cout << i << endl;
            return;
        }
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