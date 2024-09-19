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
int A[500000], DP[500000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    reverse(A, A+N);

    stack<int> stk;
    rep(i, 0, N){
        while(!stk.empty() && A[stk.top()] <= A[i]) stk.pop();
        DP[i] = stk.size();
        stk.push(i);
    }
    reverse(DP, DP+N);
    rep(i, 0, N) cout << DP[i] << ' ';
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