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

const ll mxK = 1e6+1, mod = 1e9+7;

struct Xudyh{
    ll phi[mxK], SP[mxK];
    unordered_map<ll, ll> mp;
    void init(){
        fill(phi, phi+mxK, 0);
        fill(SP, SP+mxK, 0);
        rep(i, 1, mxK){
            phi[i] += i;
            for(ll j = i*2; j < mxK; j+=i){
                phi[j] -= phi[i];
            }
            SP[i] = SP[i-1] + phi[i];
            SP[i] %= mod;
        }
    }

    ll getSP(ll N){
        if(N < mxK) return SP[N];
        if(mp.find(N) != mp.end()) return mp[N];

        ll ret = N*(N+1)/2;
        for(ll i = 2, j; i<=N; i=j+1){
            j = N/(N/i);
            ret -= (j-i+1)*getSP(N/i);
        }
        return mp[N] = ret;
    }
}Xudyh;

struct Fibo{
    ll tmp[2][2], ret[2][2], mat[2][2];

    void mul(ll A[2][2], ll B[2][2]){
        rep(i, 0, 2) rep(j, 0, 2){
            ret[i][j] = 0;
            rep(k, 0, 2) ret[i][j] += A[i][k]*B[k][j];
            ret[i][j] %= mod;
        }
        rep(i, 0, 2) rep(j, 0, 2) A[i][j] = ret[i][j];
    }

    ll kth(ll N){
        if(N == 0) return 0;
        if(N == 1) return 1;
        N--;
        tmp[0][0] = tmp[0][1] = tmp[1][0] = 1;
        tmp[1][1] = 0;
        mat[0][0] = mat[1][1] = 1;
        mat[0][1] = mat[1][0] = 0;
        while(N){
            if(N&1) mul(mat, tmp);
            mul(tmp, tmp);
            N >>= 1;
        }
        return mat[0][0];
    }

    ll sum(ll L, ll R){
        return (kth(R+2) - kth(L+1) + mod)%mod;
    }
}Fibo;

ll N;

void solve(){
    cin >> N;
    Xudyh.init();

    ll ans = 0;
    for(ll i = 1, j; i<=N; i=j+1){
        j = N/(N/i);
        ans += ((Xudyh.getSP(N/i)*2-1)%mod)*Fibo.sum(i, j)%mod;
        ans %= mod;
    }
    cout << ans << '\n';
}

void naive(){
    ll ans = 0;
    rep(i, 1, N+1) rep(j, 1, N+1){
        ans += Fibo.kth(__gcd(i, j));
        ans %= mod;
    }
    cout << ans;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
        // naive();
    }
    return 0;
}