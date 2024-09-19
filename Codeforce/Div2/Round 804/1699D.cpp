#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int tc = 1;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<int> A;
int DP[5001];
int cnt[5001];

void solve(){
    cin >> N;
    A.resize(N+1);
    rep(i, 1, N+1) cin >> A[i];
    fill(DP, DP+5001, 0);

    rep(i, 0, N+1){
        if(i > 0 && DP[i] == 0) continue;
        fill(cnt, cnt+5001, 0);
        int mx = 0;

        rep(j, i+1, N+1){
            if((j-i)%2 && mx <= (j-i)/2 && (i == 0 || A[i] == A[j])){
                DP[j] = max(DP[j], DP[i]+1);
            }
            mx = max(mx, ++cnt[A[j]]);
        }
    }
    // rep(i, 0, N+1) cout << DP[i] << ' ';
    // cout << '\n';

    fill(cnt, cnt+5001, 0);
    int mx = 0, ans = 0;
    for(int i = N; i>=0; i--){
        if((N-i)%2==0 && mx <= (N-i)/2){
            ans = max(ans, DP[i]);
        }
        mx = max(mx, ++cnt[A[i]]);
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}