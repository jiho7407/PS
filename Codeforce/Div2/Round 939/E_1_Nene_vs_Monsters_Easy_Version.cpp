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

    while(1){
        rep(i, 0, N){
            if(A[i] == 0 || A[i+1] == 0) continue;
            A[i+1] = max(0, A[i+1]-A[i]);
        }
        if(A[N-1] != 0 && A[0] != 0){
            A[0] = max(0, A[0]-A[N-1]);
        }

        bool flag = false;
        rep(i, 0, N) if(A[i] == 0){
            flag = true;
            break;
        }
        if(flag) break;
    }
    vector<int> ans;
    rep(i, 0, N) if(A[i] == 0 && A[(i+1)%N] != 0) ans.push_back((i+1)%N+1);
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x << ' ';
    cout << '\n';
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