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

int N, M;
vector<int> A, B;

bool check(int lv){
    rep(i, 0, M){
        bool flag = true;
        rep(j, 0, N){
            if(i+j*lv >= M) return false;
            if(A[j] != B[i+j*lv]){
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }
    return false;
}

void solve(){
    cin >> N; A.resize(N); rep(i, 0, N) cin >> A[i];
    cin >> M; B.resize(M); rep(i, 0, M) cin >> B[i];
    int mn = 1e5, mx = -1;
    rep(i, 1, M){
        if(check(i)){
            mn = min(mn, i-1);
            mx = max(mx, i-1);
        }
    }
    if(mn == 1e5) cout << "-1\n";
    else cout << mn << ' ' << mx << '\n';
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