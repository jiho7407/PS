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

const ll mod = 998244353;
int N;
int A[400], cnt[201];
ll DP[400][400];

bool check(int a, int b){
    a = A[a], b = A[b];
    if(a == 0){
        if(b == 0) return true;
        if(cnt[b] == 1) return true;
        return false;
    }
    else if(cnt[a] == 1){
        if(b == 0) return true;
        return false;
    }
    else{
        if(a == b) return true;
        return false;
    }
}

ll calc(int L, int R){
    if(L > R) return 1;
    if(L == R) return 0;

    ll &ret = DP[L][R];
    if(ret != -1) return ret;

    ret = 0;
    rep(k, L+1, R+1){
        if(!check(L, k)) continue;
        ret += calc(L+1, k-1) * calc(k+1, R);
        ret %= mod;
    }

    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, 2*N) cin >> A[i];
    rep(i, 0, 2*N) cnt[A[i]]++;
    rep(i, 0, 2*N) rep(j, 0, 2*N) DP[i][j] = -1;
    ll ans = calc(0, 2*N-1);
    int freecnt = 0;
    rep(i, 1, N+1) if(cnt[i] == 0) freecnt++;
    rep(i, 1, freecnt+1){
        ans *= i;
        ans %= mod;
    }
    cout << ans << '\n';
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