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
int A[10000];
int cnt[401];

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    while(M--){
        int L, R, K; cin >> L >> R >> K; L--, R--;
        fill(cnt, cnt+401, 0);
        rep(i, L, R+1) cnt[A[i]+200]++;
        rep(i, 0, 401){
            if(K <= cnt[i]){
                cout << i-200 << '\n';
                break;
            }
            K -= cnt[i];
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